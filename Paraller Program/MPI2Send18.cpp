#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int N;
	double b[10];
	MPI_Status s;
	int count;
	
	if (rank % 2 == 0)
	{
		pt >> N;
		double* a = new double [N];
		for(int i = 0; i < N; i++)
		{
			pt >> a[i];
		}
		MPI_Sendrecv(a, N, MPI_DOUBLE, rank+1, 0, b, 10, MPI_DOUBLE, rank+1, 0, MPI_COMM_WORLD, &s);
		MPI_Get_count(&s, MPI_DOUBLE, &count);
		for(int i = 0; i < count; i++)
			pt << b[i];
	}
	else
	{
		pt >> N;
		double* a = new double [N];
		for(int i = 0; i < N; i++)
		{
			pt >> a[i];
		}
		MPI_Sendrecv(a, N, MPI_DOUBLE, rank-1, 0, b, 10, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &s);
		MPI_Get_count(&s, MPI_DOUBLE, &count);
		for(int i = 0; i < count; i++)
			pt << b[i];
	}

}
