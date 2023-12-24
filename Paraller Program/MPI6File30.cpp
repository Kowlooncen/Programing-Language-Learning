#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File30");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	char name[12];
	int n = 0;
	if(rank == 0)
		pt >> name >> n;
	MPI_Bcast(name, 12, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	MPI_File f;
	MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &f);
	
	int i, j;
	pt >> i >> j;
	
	int sz = ((j - 1) * n + (i - 1) * 3 * n * n) * sizeof(int);
	 
	MPI_Datatype type;
    MPI_Type_vector(n, n, 3 * n, MPI_INT, &type);
    
    char native[7] = "native";
    MPI_File_set_view(f, sz, MPI_INT, type, native, MPI_INFO_NULL);
    
    int newsize = n * n;
    int* num = new int[newsize];
    for (int i = 0; i < newsize; i++)
        num[i] = rank;
    MPI_File_write_all(f, num, newsize, MPI_INT, MPI_STATUS_IGNORE);

    MPI_File_close(&f);
}
