#include "mpi.h"
#include "pt4.h"

#include <cmath>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int m0, p0, q0;     // sizes of the matrix blocks
int k0;             // order of the Cartesian grid (equal to sqrt(k))

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c;     // arrays to store matrix blocks in each process

MPI_Datatype MPI_BLOCK_A; // datatype for the block of the matrix A
MPI_Datatype MPI_BLOCK_B; // datatype for the block of the matrix B
MPI_Datatype MPI_BLOCK_C; // datatype for the block of the matrix C

MPI_Comm MPI_COMM_GRID = MPI_COMM_NULL;
             // communicator associated with a two-dimensional Cartesian grid

char name[20];

void Matr3GatherFile() 
{
	if (r == 0)
		pt >> name;
	MPI_Bcast(name, 20, MPI_CHAR, 0, MPI_COMM_WORLD);

	int hz = r / k0, x;
	if (hz * m0 > m)
		x = 0;
	else if ((hz + 1) * m0 > m)
		x = m - hz * m0;
	else
		x = m0;

	int lz = r % k0, l;
	if (lz * q0 > q)
		l = 0;
	else if ((lz + 1) * q0 > q)
		l = q - lz * q0;
	else 
		l = q0;

	MPI_File f;
	MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDWR | MPI_MODE_CREATE, MPI_INFO_NULL, &f);
	for (int i = 0; i < x; i++) 
	{
		int size = hz*m0*q + lz*q0 + i*q;
		MPI_File_write_at(f, size*sizeof(int), &c[q0*i], l, MPI_INT, MPI_STATUS_IGNORE);
	}	
}

void Solve() 
{
    Task("MPI9Matr30");
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

    pt >> m >> q >> m0 >> q0;
    int cs = m0 * q0;
    c = new int[cs];
    for (int i = 0; i < cs; i++)
        pt >> c[i];
    Matr3GatherFile();
    for(int i = 0; i < cs; i++)
	{
		pt << c[i];
	}
}