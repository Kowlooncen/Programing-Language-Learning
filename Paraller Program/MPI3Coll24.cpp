#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI3Coll24");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//MPI_Reduce_scatter(void* sbuf, void* rbuf, int* rcounts, MPI_Datatype datatype, 
//						MPI_Op op, MPI_Comm comm)

	int* sbuf = new int[size];
	int* rcounts = new int[size];
	for (int i = 0; i < size; ++i) 
	{
		pt >> sbuf[i];
		rcounts[i] = 1;
	}

	int r;
	MPI_Reduce_scatter(sbuf, &r, rcounts, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	pt << r;
}
