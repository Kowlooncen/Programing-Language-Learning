#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send15");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	double a;
	int N;
	MPI_Status s;
	
	pt >> a;
	pt >> N;
	
	MPI_Send(&a, 1, MPI_DOUBLE, N, 0, MPI_COMM_WORLD);
	MPI_Recv(&a, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &s);
	
	pt << a;
	pt << s.MPI_SOURCE;

}
