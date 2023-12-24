#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm6");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//the total of the slave process with number 1 is equal to K
//using MPI_Comm_split output a[i] to these slave processes	
	
	MPI_Comm comm;
	int K, N;
	if(rank == 0)
	{
		pt >> K;
		N = 1;
	}
	else{
		pt >> N;
	}
	

	int color = N ;
	MPI_Comm_split(MPI_COMM_WORLD, color, rank, &comm);
	
	if(N == 1){
		double* sendbuf = new double[1];
		int* sendcounts = new int[1];
		int* displs = new int[1];
		double x;
		
		if(rank == 0)
		{
			sendbuf = new double[K+1];
			sendcounts = new int[K+1];
			displs = new int[K + 1];
			
			for(int i = 1; i < K+1; i++)
			{
				pt >> sendbuf[i];
			}
			sendcounts[0] = 0;
			for (int i = 1; i < K + 1; i++)
				sendcounts[i] = 1;
			//fill(sendcounts, sendcounts + K + 1, 1);
	
			for (int i = 0; i < K + 1; i++)
				displs[i] = i;
		}
		//	int MPIAPI MPI_Scatterv(
		//  _In_  void         *sendbuf,
		//  _In_  int          *sendcounts,
		//  _In_  int          *displs,
		//        MPI_Datatype sendtype,
		//  _Out_ void         *recvbuf,
		//        int          recvcount,
		//        MPI_Datatype recvtype,
		//        int          root,
		//        MPI_Comm     comm
		//);
		MPI_Scatterv(sendbuf, sendcounts, displs, MPI_DOUBLE, &x, 1, MPI_DOUBLE, 0, comm);
		if (rank != 0)
			pt << x;
	}
}
