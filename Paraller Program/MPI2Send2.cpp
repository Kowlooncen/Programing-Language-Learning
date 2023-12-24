#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	double a;
	void *buffer;
	MPI_Status s;
	
	if (rank > 0)
	{
		pt >> a;
		int sz = sizeof(double) + MPI_BSEND_OVERHEAD;
        buffer = (double*)malloc(sz);
       	MPI_Buffer_attach(buffer, sz);
        MPI_Bsend(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

        MPI_Buffer_detach(&buffer, &sz);
        free(buffer);
	}
	else
	{
		for (int i = size-1; i >= 1; i--)
		{
			double b;
			MPI_Recv(&b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &s);
			pt << b;
		}
	}
}
			
			
			

