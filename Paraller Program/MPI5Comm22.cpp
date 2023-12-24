#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm22");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm comm_cart;
	int dims[3] = {2 ,2, size/4};
	int periods[3] = {0, 0, 0};
	MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, 0, &comm_cart);
	 
	MPI_Comm new_comm;
	int remain_dims[3] = {1, 1, 0};
	MPI_Cart_sub(comm_cart, remain_dims, &new_comm);
	
	double x;
	pt >> x;
	
	double res;
	MPI_Allreduce(&x, &res, 1, MPI_DOUBLE, MPI_SUM, new_comm);
	
	pt <<res;
}
