#include "mpi.h"
#include "pt4.h"
#include <vector>

using namespace std;

void Solve()
{
    Task("MPI5Comm2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//using the MPI_Comm_group, MPI Group excl, and MPI_Comm_create functions.
	MPI_Comm new_comm;
	int odd_sz = size / 2;
	int res_sz = size - odd_sz;
	Show(odd_sz);

	double* a = new double[2];
	vector<double> res(2*odd_sz);
	
	if (rank % 2 == 1)
	{
		pt >> a[0] >> a[1];
	}
	vector<int> ranks(2*odd_sz);
	for(int i = 0; i < res_sz; i++)
	{
		ranks[i] = i*2;
	}
	MPI_Group old_group, new_group;
	//建立一个通信组对应的新进程组
	MPI_Comm_group(MPI_COMM_WORLD, &old_group);
	MPI_Group_excl(old_group, res_sz, &ranks[0], &new_group);
	MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm);
	
	if (rank % 2 == 1)
	{
		MPI_Allgather(&a[0],2,MPI_DOUBLE, &res[0],2,MPI_DOUBLE,new_comm);
//		for (auto &i : res) {
//			pt << i;
//		}
		vector<double>::iterator it;
		for(it = res.begin(); it != res.end(); it++)
		{
			pt << *it;
		}
	}
}
