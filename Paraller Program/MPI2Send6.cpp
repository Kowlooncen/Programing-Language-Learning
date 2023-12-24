#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI2Send6");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
	double a[size];
	void *buffer;
	MPI_Status s;
	Show(size);
	if (rank > 0)
	{
        MPI_Recv(&a[rank], 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &s);
		pt << a[rank];
	}
	else
	{
		for(int i = 0; i < size - 1; i++)
			pt >> a[i];
		int sz = (size-1)*sizeof(double) + MPI_BSEND_OVERHEAD;
        buffer = (double*)malloc(sz);
       	MPI_Buffer_attach(buffer, sz);
       	for(int i = 0; i < size-1; i++)
        	MPI_Bsend(&a[i], 1, MPI_DOUBLE, size-1-i, 0, MPI_COMM_WORLD);

        MPI_Buffer_detach(&buffer, &sz);
        free(buffer);
	}
		
}
