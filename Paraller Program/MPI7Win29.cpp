#include "pt4.h"
#include "mpi.h"
void Solve()
{
	Task("MPI7Win29");
	int flag;
	MPI_Initialized(&flag);
	if (flag == 0)
		return;
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int* row = new int[size + 2];
	int* array = new int[size + 2];
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		pt >> row[i];
		sum += row[i];
	}
	row[size] = sum;
	row[size + 1] = 1;
	MPI_Win window;
	MPI_Win_create(row, (size + 2) * 4, 4, MPI_INFO_NULL, MPI_COMM_WORLD, &window);
	if (rank == 0)
	{
		int* tmp = new int[size + 2];
		for (int i = 0; i < size + 2; i++) 
			tmp[i] = row[i];
		for (int i = 1; i < size; i++)
		{
			MPI_Win_lock(MPI_LOCK_SHARED, i, 0, window);
			MPI_Get(tmp, size + 2, MPI_INT, i, 0, size + 2, MPI_INT, window);
			MPI_Win_unlock(i, window);
			
			if (tmp[size] <= row[size])
			{
				if (tmp[size] == row[size]) row[size + 1]++;
				else row[size + 1] = 1;

				for (int j = 0; j < size + 1; j++)
				{
					row[j] = tmp[j];
				}
			}
		}
		MPI_Barrier(MPI_COMM_WORLD);
		for (int i = 0; i < size + 2; i++)
		{
			pt << row[i];
		}
	}
	else
	{
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Win_lock(MPI_LOCK_SHARED, 0, 0, window);
		MPI_Get(array, size + 2, MPI_INT, 0, 0, size + 2, MPI_INT, window);
		MPI_Win_unlock(0, window);

		for (int i = 0; i < size + 2; i++)
		{
			pt << array[i];
		}
	}
}