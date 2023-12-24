#include "mpi.h"
#include "pt4.h"

using namespace std;

void Solve()
{
    Task("MPI3Coll17");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//MPI_Alltoallv(void* sbuf, int* scounts, int* sdispls, MPI_Datatype stype, void* rbuf, 
	//int* rcounts, int* rdispls, MPI_Datatype rtype, MPI_Comm comm)
	
	double* sbuf = new double[(size + 1)];
    double* rbuf = new double[(size * 2)];
    
    double x;
    for (int i = 0; i < size + 1; i++)
    {
        pt >> x;
        sbuf[i] = x;
    }
	
	int* scounts = new int[size];
    int* sdispls = new int[size];
    int* rcounts = new int[size];
    int* rdispls = new int[size];

    for (int i = 0; i < size; i++)
    {
        scounts[i] = 2;
        sdispls[i] = i;
    }

    for (int i = 0; i < size; i++)
    {
        rcounts[i] = 2;
        rdispls[i] = (2 * i);
    }

    MPI_Alltoallv(sbuf, scounts, sdispls, MPI_DOUBLE, rbuf, rcounts, rdispls, MPI_DOUBLE, MPI_COMM_WORLD);

    for (int i = 0; i < 2 * size; ++i)
    {
        pt << rbuf[i];
    }
}
