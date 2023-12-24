#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File21");
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
	
	MPI_File f;
	MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_RDONLY, MPI_INFO_NULL, &f);

    MPI_Datatype type;
    MPI_Type_vector(3, 1, size, MPI_INT, &type);

    char native[7] = "native";
    MPI_File_set_view(f, rank * sizeof(int), MPI_INT, type, native, MPI_INFO_NULL);

    int numbers[3];
    MPI_File_read_all(f, numbers, 3, MPI_INT, MPI_STATUS_IGNORE);

    pt << numbers[0] << numbers[1] << numbers[2];

    MPI_File_close(&f);
}
