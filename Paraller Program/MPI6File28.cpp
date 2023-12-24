#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI6File28");
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
	MPI_File_open(MPI_COMM_WORLD, name, MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &f);
	
	int n = 0;
	pt >> n;

	double* num = new double[size/2];
	for(int i = 0; i < size/2; i++)
	{
		pt >> num[i]; 
	}
	
	MPI_Datatype type;
	MPI_Type_vector(size/2, 1, size, MPI_DOUBLE, &type);
	
	char native[7] = "native";
	MPI_File_set_view(f, (n - 1) * sizeof(double), MPI_DOUBLE, type, native, MPI_INFO_NULL);
	 
	MPI_File_write_all(f, num, size/2, MPI_DOUBLE,MPI_STATUS_IGNORE);
	
	MPI_File_close(&f);
}
