#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm16");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double A;
	if (rank == 0 || rank == 1) 
		pt >> A;
	
//	int MPIAPI MPI_Cart_sub(
//        MPI_Comm comm,
//  _In_  int      *remain_dims,
//  _Out_ MPI_Comm *newcomm
//);
	
	int N = size / 2;
	int dims[] = {N, 2};
	int periods[] = {0, 0};
	int remain_dims[] = {1, 0};
	
	MPI_Comm comm_cart;
	MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, false, &comm_cart);

	MPI_Comm newcomm;
	MPI_Cart_sub(comm_cart, remain_dims, &newcomm);
	MPI_Bcast(&A, 1, MPI_DOUBLE, 0, newcomm);
	pt << A;
	
}
