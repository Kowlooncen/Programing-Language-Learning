#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int a;
	MPI_Status s;
	if (rank > 0)
	{
		pt >> a;
		MPI_Ssend(&a, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD);
		if (rank != size-1)
			MPI_Recv(&a, 1, MPI_DOUBLE, rank+1, 0, MPI_COMM_WORLD, &s);
		else 
			MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s);
		pt << a; 
	}
	else
	{
		MPI_Recv(&a, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, &s);
		pt << a;

		pt >> a;
		MPI_Ssend(&a, 1, MPI_DOUBLE, size-1, 0, MPI_COMM_WORLD);
	}
}
