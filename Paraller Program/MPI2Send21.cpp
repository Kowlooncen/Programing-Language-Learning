#include "mpi.h"
#include "pt4.h"

using namespace std;

void Solve()
{
    Task("MPI2Send21");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status s;
    Show(size);

    int L;
    double a;
    int N;
    
    
    if(rank > 0)
    {
    	
    	pt >> L;
    	for(int i = 0; i < L; i ++)
    	{
    		pt >> a;
			pt >> N;
			MPI_Send(&a, 1, MPI_DOUBLE, 0, N, MPI_COMM_WORLD);
		}
	}
	else{
		double b;
		for(int i = 1; i <= 2*size; i++)
		{
			MPI_Recv(&b, 1, MPI_DOUBLE, MPI_ANY_SOURCE, i, MPI_COMM_WORLD, &s);
			pt << b;
		}
	}
}
