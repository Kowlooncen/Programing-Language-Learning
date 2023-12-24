#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI8Inter11");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
    MPI_Comm peer;
    MPI_Comm_dup(MPI_COMM_WORLD, &peer);
    int C;
    pt >> C;
    MPI_Comm comm1;

    if (C == 0)
    {
        MPI_Comm_split(MPI_COMM_WORLD, MPI_UNDEFINED, rank, &comm1);
        pt << -1;
        return;
    }
    else
    {
        MPI_Comm_split(MPI_COMM_WORLD, C, rank, &comm1);
    }

    int R;
    MPI_Comm_rank(comm1, &R);
    pt << R;
    
    MPI_Comm inter;
    int lead = 0;
    if (rank == 0)
    {
        lead = size / 2;
    }
    MPI_Intercomm_create(comm1, 0, peer, lead, 100, &inter);
    
    int k1;
    MPI_Comm_rank(comm1,&k1);
    
    int k2;
    MPI_Comm_remote_size(inter, &k2);

    int *X = new int [k2];
    int R1, res;
    pt >> R1;
    int root = MPI_PROC_NULL;
    if (C == 1)
    {
    	if (k1 == R1)
    	{
    		for(int i = 0; i < k2; i++)
	    	{
	    		pt >> X[i];
			}
			root=MPI_ROOT;
		}	
    }
	else{
    	root=R1;
	}
	MPI_Scatter(X, 1, MPI_INT, &res, 1, MPI_INT, root, inter);
	if(C == 2) pt << res;
}
