#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm24");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	
	int M, N;
	if(rank == 0){
		pt >> M >> N;
	}
	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	int range = M*N-1;
	int x,y;
	MPI_Comm new_comm;
	
	int dims[] = {M, N};
	int periods[] = {0, 1};
	
	MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &new_comm);
	
	if(rank <= range)
	{
		pt >> x >> y;
		int coord[] = {x, y};
		int nrank;
        if (!MPI_Cart_rank(new_comm, coord, &nrank))
            pt << nrank;
        else
            pt << -1;
	}
}
