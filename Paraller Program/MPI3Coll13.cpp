#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI3Coll13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
//	int MPIAPI MPI_Allgatherv(
//  _In_  void         *sendbuf,
//        int          sendcount,
//        MPI_Datatype sendtype,
//  _Out_ void         *recvbuf,
//  _In_  int          *recvcounts,
//  _In_  int          *displs,
//        MPI_Datatype recvtype,
//        MPI_Comm     comm
//);

	int sz = 0;
	for(int i = 0; i < size; i++)
	{
		sz = sz + (i + 2);
	}

	int* arr_s = new int [rank + 2];
	int* arr_r = new int [sz];
	int* rcounts = new int [size];
    int* displs = new int [size];
	
	for (int i = 0; i < rank + 2; i ++)
	{
		pt >> arr_s[i];
	}
	
	for (int i = 0; i < size; i++) {
        rcounts[i] = i + 2;
        if (i == 0) 
		{
            displs[i] = 0;
            continue;
        }
        displs[i] = displs[i-1] + rcounts[i-1];
    }

	MPI_Allgatherv(arr_s, rank + 2, MPI_INT, arr_r, rcounts, displs, MPI_INT, MPI_COMM_WORLD);
	
	for (int i = 0; i < sz; i ++)
	{
		pt<< arr_r[i];
	}
}
