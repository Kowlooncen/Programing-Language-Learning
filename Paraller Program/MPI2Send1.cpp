#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send1");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm;
	MPI_Comm_size(comm, &size);
	int buf[10]={0};
	MPI_Send(buf, 15, MPI_INT, size+1, 8, comm);
	MPI_Send(buf, 8, MPI_INT, size-1, 15, comm);
}
