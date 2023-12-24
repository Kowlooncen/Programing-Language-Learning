#include "mpi.h"
#include "pt4.h"
///////////////////////////////////////
#include <cmath>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int m0, p0, q0;     // sizes of the matrix blocks
int k0;             // order of the Cartesian grid (equal to sqrt(k))

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c;     // arrays to store matrix blocks in each process

MPI_Datatype MPI_BLOCK_B; // datatype for the block of the matrix B
MPI_Datatype MPI_BLOCK_C; // datatype for the block of the matrix C

MPI_Comm MPI_COMM_GRID = MPI_COMM_NULL;
             // communicator associated with a two-dimensional Cartesian grid

void Matr3CreateTypeBlock(int m0, int p0, int p, MPI_Datatype* t)
{
	MPI_Type_vector(m0, p0, p, MPI_INT, t);
	MPI_Type_commit(t);
}

void Matr3GatherData()
{
	Matr3CreateTypeBlock(m0, q0, q0 * k0, &MPI_BLOCK_C);
	if (r != 0) 
		MPI_Send(c, m0*q0, MPI_INT, 0, 0, MPI_COMM_WORLD);
	else 
		MPI_Sendrecv(c, m0*q0, MPI_INT, 0, 0, c_, 1, MPI_BLOCK_C, 0, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
	
	if (r == 0)
	{
		for (int i = 1; i < k; i++)
			MPI_Recv(c_ + ((i % k0) * q0 + i / k0 * m0 * q0 * k0), 1, MPI_BLOCK_C, i, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
	}
}

void Solve()
{
    Task("MPI9Matr27");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;
    k0 = (int)floor(sqrt((double)k) + 0.1);
	
	if (rank == 0)
	{
		pt >> m >> q;
	}
	pt >> m0 >> q0;
	int sz1 = m0 * k0;
	int sz2 = q0 * k0;
	int sz3 = m0 * q0;
	c = new int[sz3];
	for (int i = 0; i < sz3; i++) 
		pt >> c[i];
		
	c_ = new int[sz1 * sz2];
	Matr3GatherData();
	
	if (rank == 0)
		for (int i = 0; i < sz1; i++)
			for (int j = 0; j < sz2; j++)
				if (i < m && j < q) 
					pt << c_[j + i * sz2];
}
