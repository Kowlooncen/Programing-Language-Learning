#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File9");
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
	
	MPI_Offset s = rank * sizeof(int);
	MPI_File_seek(f, s, MPI_SEEK_SET);
	MPI_Offset offs;
	MPI_File_get_size(f, &offs);
	
	int sz = offs / sizeof(int);
	
	MPI_Status sta;
	int* num = new int[rank + 1];
	MPI_File_read_all(f, num, rank + 1, MPI_INT, &sta);
	
	for(int i = 0; i < rank + 1; i++)
		if(rank + i < sz)
			pt << num[i];
	MPI_File_close(&f);
}
