#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File16");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm comm;
	char name[20];
	if(rank == 0) pt >> name;
	MPI_Bcast(name, 20, MPI_CHAR, 0, MPI_COMM_WORLD);
	int N;
	pt >> N;
	int color = N == 0 ? MPI_UNDEFINED : 0;
	MPI_Comm_split(MPI_COMM_WORLD, color, size - rank, &comm);
	if(comm == MPI_COMM_NULL) return;
	MPI_File f;
	MPI_File_open(comm, name, MPI_MODE_RDWR | MPI_MODE_CREATE, MPI_INFO_NULL, &f);
	MPI_Comm_size(comm, &size);
	MPI_Comm_rank(comm, &rank);
	double x[N];
	for(int i = N-1; i >= 0; i--)
		pt >> x[i];
	MPI_File_write_ordered(f, x, N, MPI_DOUBLE, MPI_STATUS_IGNORE);
	MPI_File_close(&f);
}
