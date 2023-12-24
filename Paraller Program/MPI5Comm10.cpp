#include "mpi.h"
#include "pt4.h"
using namespace std;
void Solve()
{
    Task("MPI5Comm10");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int N;
	pt >> N;
	MPI_Comm nc;
	MPI_Comm_split(MPI_COMM_WORLD, N, rank, &nc);
	
	int A;
	pt >> A;
	int new_sz;
	MPI_Comm_size(nc, &new_sz);
	int* res = new int [new_sz];
	MPI_Allgather(&A, 1, MPI_INT, &res[0], 1, MPI_INT, nc);
	for(int i = 0; i < new_sz; i++){
		pt << res[i];
	}
}
