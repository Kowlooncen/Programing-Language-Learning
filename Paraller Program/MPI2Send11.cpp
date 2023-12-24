#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send11");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	double a;
	MPI_Status s;
	if (rank > 0)
	{
//		pt >> a;
//		MPI_Send(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
//		MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s);
//		pt << a; 
		MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s);
		pt << a; 
		pt >> a;
		MPI_Ssend(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else
	{
		pt >> a;
		for (int i = 1; i < size; ++i)
			MPI_Ssend(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
		for (int i = 1; i < size; ++i)
		{
			MPI_Recv(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &s);
			pt << a;
		} 
	}
}
