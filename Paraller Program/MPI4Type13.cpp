#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI4Type13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//1 real number rank integers
	//using pack/unpack, collectice
	int sz = sizeof(double) + sizeof(int) * (size - 1);
	char* buff = new char[sz];
	int position;
	double x;
	int* outbuf = new int[size - 1];
	std::fill(outbuf, outbuf + size - 1, 0);
	
	if (rank != 0) {
		pt >> x;
		for (int i = 0; i < rank; ++i)
			pt >> outbuf[i];
		position = 0;
		MPI_Pack(&x, 1, MPI_DOUBLE, buff, sz, &position, MPI_COMM_WORLD);
		MPI_Pack(outbuf, size - 1, MPI_INT, buff, sz, &position, MPI_COMM_WORLD);
	}

	
	int allsize = sz * (size - 1);
	char* inbuf = new char[allsize];
	MPI_Gather(buff, sz, MPI_PACKED, inbuf, sz, MPI_PACKED, 0, MPI_COMM_WORLD);

	
	if (rank == 0) {
		position = sz;
		for (int i = 1; i < size; ++i) {
			MPI_Unpack(inbuf, sz, &position, &x, 1, MPI_DOUBLE, MPI_COMM_WORLD);
			MPI_Unpack(inbuf, sz, &position, outbuf, size - 1, MPI_INT, MPI_COMM_WORLD);
			pt << x;
			for (int j = 0; j < i; ++j)
				pt << outbuf[j];
		}
	}
}
