#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm14");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int N;
	if(rank == 0) 
		pt >> N;
	
	MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
//	int MPIAPI MPI_Cart_create(
//        MPI_Comm              comm_old,
//        int                   ndims,
//        _In_count_(ndims) int *dims,
//        _In_count_(ndims) int *periods,
//        int                   reorder,
//  _Out_ MPI_Comm              *comm_cart
//);
	int* dims = new int[2];
	dims[0] = N;
	dims[1] = size/N;
	
	int* periods = new int[2];
	periods[0] = 0;
	periods[1] = 0;
	
	MPI_Comm comm_cart;
	MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, false, &comm_cart);
	
	if(comm_cart != MPI_COMM_NULL){
		int coord[2];
		MPI_Cart_coords(comm_cart, rank, 2, coord);
		pt << coord[0] << coord[1];
	}
}
