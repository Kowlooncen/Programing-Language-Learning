#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File19");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	char name[12];
	if(rank == 0) pt >> name;
	MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);
	int N;
	pt >> N;
	MPI_File f;
	MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &f);
	int sz;
	MPI_Type_size(MPI_DOUBLE, &sz);
	MPI_Offset offset = (size - rank - 1) * sz * 6;
	MPI_Datatype t0, t;
	MPI_Type_vector(1, 1, 6, MPI_DOUBLE, &t0);
	MPI_Type_create_resized(t0, 0, 1, &t);
	MPI_File_set_view(f, offset, MPI_DOUBLE, t, "native", MPI_INFO_NULL);
	double x;
	MPI_File_read_at_all(f, (N-1)*sz, &x, 1, MPI_DOUBLE, MPI_STATUS_IGNORE);
	pt << x;
	MPI_File_close(&f);
}
