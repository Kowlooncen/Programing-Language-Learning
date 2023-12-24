#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File12");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	char name[12];
	if(rank == 0)
		pt >> name;
	MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);
	
	MPI_Comm comm;
	int color = 0;
	
	int x;
	pt >> x;
	
	if(x != 0)
		color = 1;
		
	if(color == 0)
		MPI_Comm_split(MPI_COMM_WORLD, MPI_UNDEFINED, rank, &comm);
	else
		MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);
		
	if(comm == MPI_COMM_NULL)
		return;
	MPI_File f;
	MPI_File_open(comm, name, MPI_MODE_WRONLY, MPI_INFO_NULL, &f);
	
	MPI_Offset off = (x - 1) * sizeof(double);
	
	int z = 0;
	MPI_Comm_rank(comm, &z);
	double s = z * 1.0;
	
	MPI_File_write_at_all(f, off, &s, 1, MPI_DOUBLE, MPI_STATUSES_IGNORE);
	
	MPI_File_close(&f);
}
