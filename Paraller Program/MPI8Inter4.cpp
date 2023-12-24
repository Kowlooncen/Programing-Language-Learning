#include "pt4.h"
#include "mpi.h"
#include <vector>

using namespace std;

void Solve() {
  
    Task("MPI8Inter4");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int C, X, Y;
    pt >> C >> X >> Y;

    MPI_Comm tmp, comm1, comm2;
    MPI_Comm_split(MPI_COMM_WORLD, C, rank, &tmp);

    int R;
    MPI_Comm_rank(tmp, &R);
    pt << R;

    if(C == 0) 
	{
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 1, 1, &comm1);
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 2, 2, &comm2);
    }
    else if (C == 1) 
	{
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 0, 1, &comm1);
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 2, 12, &comm2);
    }
    else if (C == 2) 
	{
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 0, 2, &comm1);
        MPI_Intercomm_create(tmp, 0, MPI_COMM_WORLD, 1, 12, &comm2);
    }

    if (C != 1) 
	{
        MPI_Send(&Y, 1, MPI_INT, R, 0, comm1);
        MPI_Send(&X, 1, MPI_INT, R, 0, comm2);
    }
    else 
	{
        MPI_Send(&X, 1, MPI_INT, R, 0, comm1);
        MPI_Send(&Y, 1, MPI_INT, R, 0, comm2);
    }

    int m, n;
    MPI_Recv(&n, 1, MPI_INT, R, 0, comm1, MPI_STATUSES_IGNORE);
    MPI_Recv(&m, 1, MPI_INT, R, 0, comm2, MPI_STATUSES_IGNORE);

    if (C != 1)
        pt << m << n;
    else
        pt << n << m;

}