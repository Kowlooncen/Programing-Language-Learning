#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send8");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int a;
	MPI_Status s;
	
	if(rank > 0)
	{
		pt >> a;
		if (a!=0)
		{
			MPI_Send(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);	
		}	
	}
	else
	{
		int b;
		MPI_Recv(&b, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
		
		pt << b;
		MPI_Recv(&b, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
		pt<<b;
	}
}
