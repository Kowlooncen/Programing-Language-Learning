#include "pt4.h"
#include "mpi.h"
void Solve()
{
	Task("MPI8Inter5");
	int flag;
	MPI_Initialized(&flag);
	if (flag == 0)
		return;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int X;
	pt >> X;
	
	MPI_Comm peer;
	MPI_Comm_dup(MPI_COMM_WORLD, &peer);
	
	MPI_Group group, group2;
	MPI_Comm_group(MPI_COMM_WORLD, &group);
	
	int hs = size/2;
	int(*range)[3] = (int(*)[3])malloc(sizeof(int) * hs * 3);

	for (int i = 0; i < hs; i++)
	{
		if (rank < hs)
		{
			range[i][0] = i; 
			range[i][1] = i; 
			range[i][2] = 1;
		}
		else
		{
			range[i][0] = i + hs; 
			range[i][1] = i + hs; 
			range[i][2] = 1;
		}
	}
	MPI_Group_range_incl(group, hs, range, &group2);
	
	MPI_Comm local;
	MPI_Comm_create(MPI_COMM_WORLD, group2, &local);

	int R1;
	MPI_Comm_rank(local, &R1);

	pt << R1;
	MPI_Comm inter1;
	int lead = 0;
	if (rank == 0)
	{
		lead = hs;
	}
	MPI_Intercomm_create(local, 0, MPI_COMM_WORLD, lead, 100, &inter1);


	int* ranks = new int[hs/2];
	for (int i = 0; i < hs/2; i++)
	{
		if (rank < hs)
		{
			ranks[i] = i * 2;
		}
		else
		{
			ranks[hs/2 - i - 1] = i*2 + 1;
		}
	}

	MPI_Group new_group;
	MPI_Group_incl(group2, hs/2, ranks, &new_group);
	MPI_Comm inter2 = MPI_UNDEFINED;
	MPI_Comm_create(inter1, new_group, &inter2);
	int R2;
	
	if (MPI_Comm_rank(inter2, &R2) == MPI_SUCCESS)
	{
		pt << R2;
		MPI_Send(&X, 1, MPI_INT, R2, 0, inter2);
		int Y;
		MPI_Recv(&Y, 1, MPI_INT, R2, 0, inter2, MPI_STATUSES_IGNORE);
		pt << Y;
	}
	
}