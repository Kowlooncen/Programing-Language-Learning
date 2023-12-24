#include "mpi.h"
#include "pt4.h"

void Solve()
{
  
    Task("MPI8Inter1");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int X, R;
	int lead = 0;
	int hs = size / 2;
    int* r1 = new int[hs];
    int* r2 = new int[hs];

    pt >> X;

    MPI_Comm comm, peer, inter;
    MPI_Group old_group, g1, g2;
    MPI_Status s;
    MPI_Comm_dup(MPI_COMM_WORLD, &peer);
    MPI_Comm_group(MPI_COMM_WORLD, &old_group);

    for (int i = 0; i < hs; i++)
        r1[i] = 2 * i;

    MPI_Group_incl(old_group, hs, r1, &g1);

    for (int i = 0; i < hs; i++)
        r2[i] = r1[i] + 1;

    MPI_Group_incl(old_group, hs, r2, &g2);

    if (rank % 2 == 0) 
		MPI_Comm_create(MPI_COMM_WORLD, g1, &comm); 
	else 
		MPI_Comm_create(MPI_COMM_WORLD, g2, &comm);

    MPI_Comm_rank(comm, &R);
    pt << R;

    if (rank % 2 == 0)
        lead = 1;

    MPI_Intercomm_create(comm, 0, peer, lead, 100, &inter);
    MPI_Send(&X, 1, MPI_INT, R, 0, inter);
    int l;
    MPI_Recv(&l, 1, MPI_INT, R, 0, inter, &s);

    pt << l;

}