#include "pt4.h"
#include "mpi.h"
void Solve()
{
    Task("MPI7Win30");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
	int* row = new int[size + 2];
	int* res = new int[size + 2];
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		pt >> row[i];
		sum += row[i];
	}
	row[size] = sum;
	row[size + 1] = 1;
	MPI_Win window;
	MPI_Group group, set;
	MPI_Comm_group(MPI_COMM_WORLD, &group);

	if (rank == 0)
	{

		MPI_Win_create(row, (size + 2) * 4, 4, MPI_INFO_NULL, MPI_COMM_WORLD, &window);
		for (int i = 1; i < size; i++)
		{
			int k[1] = { i };
			MPI_Group_incl(group, 1, k, &set);
			MPI_Win_post(set, 0, window);
			MPI_Win_wait(window);
			MPI_Win_post(set, 0, window);
			MPI_Win_wait(window);
		}
		MPI_Barrier(MPI_COMM_WORLD);

		for (int i = 0; i < size + 2; i++)
		{
			pt << row[i];
		}
		
	}
	else
	{	
		MPI_Win_create(nullptr, (size + 2) * 4, 4, MPI_INFO_NULL, MPI_COMM_WORLD, &window);
		int* tmp = new int[size + 2];
		int k[1] = { 0 };
		MPI_Group_incl(group, 1, k, &set);
		MPI_Win_start(set, 0, window);
		MPI_Get(tmp, size + 2, MPI_INT, 0, 0, size + 2, MPI_INT, window);
		MPI_Win_complete(window);
		if (row[size] <= tmp[size])
		{
			if (row[size] == tmp[size]) row[size + 1] += tmp[size + 1];
			for (int j = 0; j < size + 2; j++)
			{
				tmp[j] = row[j];
			}
		}
		MPI_Win_start(set, 0, window);
		MPI_Put(tmp, size + 2, MPI_INT, 0, 0, size + 2, MPI_INT, window);
		MPI_Win_complete(window);
		MPI_Barrier(MPI_COMM_WORLD);
		
		MPI_Win_lock(MPI_LOCK_SHARED, 0, 0, window);
		MPI_Get(res, size + 2, MPI_INT, 0, 0, size + 2, MPI_INT, window);
		MPI_Win_unlock(0, window);
		for (int i = 0; i < size + 2; i++)
		{
			pt << res[i];
		}
	}
}