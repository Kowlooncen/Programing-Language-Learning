#include "pt4.h"
#include "mpi.h"
void Solve()
{
    Task("MPI8Inter13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm;
    
    MPI_Comm peer;
    MPI_Comm_dup(MPI_COMM_WORLD, &peer);
    
    int C;
    pt >> C;
    
    if (C == 0)
    {
        MPI_Comm_split(MPI_COMM_WORLD, MPI_UNDEFINED, rank, &comm);
        pt << -1;
        return;
    }
    else
    {
        MPI_Comm_split(MPI_COMM_WORLD, C, rank, &comm);
    }

    int R;
    MPI_Comm_rank(comm, &R);
    pt << R;
    
    MPI_Comm inter;
    int lead = 0;
    if (rank == 0)
    {
        lead = size / 2;
    }

    MPI_Intercomm_create(comm, 0, peer, lead, 100, &inter);
    
    double X, Y;
    pt >> X;
    
    if (C == 1)
    {
        MPI_Allreduce(&X, &Y, 1, MPI_DOUBLE, MPI_MAX, inter);
    }
    else
    {
        MPI_Allreduce(&X, &Y, 1, MPI_DOUBLE, MPI_MIN, inter);
    }
    pt << Y;
}