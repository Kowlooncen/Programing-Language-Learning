#include "mpi.h"
#include "pt4.h"

#include <cmath>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int m0, p0, q0;     // sizes of the matrix blocks
int k0;             // order of the Cartesian grid (equal to sqrt(k))

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c, *t; // arrays to store matrix blocks in each process

MPI_Datatype MPI_BLOCK_A; // datatype for the block of the matrix A
MPI_Datatype MPI_BLOCK_B; // datatype for the block of the matrix B
MPI_Datatype MPI_BLOCK_C; // datatype for the block of the matrix C

MPI_Comm MPI_COMM_GRID = MPI_COMM_NULL;
             // communicator associated with a two-dimensional Cartesian grid
MPI_Comm MPI_COMM_ROW = MPI_COMM_NULL;
             // communicator associated with rows of a two-dimensional grid
MPI_Comm MPI_COMM_COL = MPI_COMM_NULL;
             // communicator associated with columns of a two-dimensional grid
             
void Matr4CreateCommGrid(MPI_Comm& comm) 
{
	int dims[2] = {k0, k0};
	int periods[2] = {0, 0};
	MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &comm);
}

void Matr4CreateCommCol(MPI_Comm grid, MPI_Comm& col) 
{
	int remain_dims[2] = {1, 0};
	MPI_Cart_sub(grid, remain_dims, &col);
}

void Solve()
{
    Task("MPI9Matr34");
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

	pt >> p0 >> q0;
	
	int bs = p0 * q0;
	b_ = new int[bs];
	
	for (int i = 0; i < bs; ++i)
		pt >> b_[i];
	
	Matr4CreateCommGrid(MPI_COMM_GRID);
	Matr4CreateCommCol(MPI_COMM_GRID, MPI_COMM_COL);
	
	int gr, cr;
	MPI_Comm_rank(MPI_COMM_GRID, &gr);
	MPI_Comm_rank(MPI_COMM_COL, &cr);
	
	int cord[2];
	MPI_Cart_coords(MPI_COMM_GRID, gr, 2, cord);
	pt << cord[0] << cord[1] << cr;
	
	int d;
	if (cr == 0) 
		d = k0 - 1; 
	else 
		d = cr - 1;

	MPI_Sendrecv_replace(b_, bs, MPI_INT, d, 0, (cr + 1) % k0, 0, MPI_COMM_COL, MPI_STATUSES_IGNORE);
	
	for (int i = 0; i < bs; ++i)
		pt << b_[i];
}
