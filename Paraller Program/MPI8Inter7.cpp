#include "pt4.h"
#include "mpi.h"

void Solve()
{

    Task("MPI8Inter7");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm comm, inter1, peer;
    MPI_Status s;
    MPI_Comm_dup(MPI_COMM_WORLD, &peer);
    
    int c, color, x, lead = 0;
    pt >> c;

	int hs = size/2;
    if (rank < hs)
        color = 0;
    else
        color = 1;

    MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);

    int r;
    MPI_Comm_rank(comm, &r);
    pt << r;
    
    if (rank < hs)
        lead = hs;
    MPI_Intercomm_create(comm, 0, peer, lead, 100, &inter1);
    
    MPI_Comm inter2;
	int sz;
    MPI_Comm_remote_size(inter1, &sz);
	MPI_Comm_split(inter1, c, size - rank - 1, &inter2);
    
	int r2, s2, sz2;
    MPI_Comm_rank(inter2, &r2);
    MPI_Comm_size(inter2, &s2);
    MPI_Comm_remote_size(inter2, &sz2);
    int* Y = new int[sz2];

    if (s2 > 1 && c == 1) 
	{
        pt << r2;
        pt >> x;
        MPI_Send(&x, 1, MPI_INT, 0, 0, inter2);
        MPI_Recv(&x, 1, MPI_INT, 0, 0, inter2, &s);
        pt << x;
    }
    if (s2 == 1 && c == 1) 
	{
        for (int i = 0; i < sz2; i++) 
		{
            pt >> Y[i];
            MPI_Recv(&x, 1, MPI_INT, i, 0, inter2, &s);
            pt << x;
            MPI_Send(&Y[i], 1, MPI_INT, i, 0, inter2);
        }
    }

}