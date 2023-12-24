#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm27");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	double A;
	pt >> A;
	
	MPI_Comm new_comm;
	
	int k = size / 4;
	int dims[] = {2, 2, k};
	int periods[] = {0, 0, 1};
	MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, 0, &new_comm);
	
	int rank_source, rank_dest;
	MPI_Cart_shift(new_comm, 2, 1, &rank_source, &rank_dest);
	
	MPI_Status s;
	MPI_Sendrecv_replace(&A, 1, MPI_DOUBLE, rank_dest, 0, rank_source, 0, new_comm, &s);
	pt << A;
}
