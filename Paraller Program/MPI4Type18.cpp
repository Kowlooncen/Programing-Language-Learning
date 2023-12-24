#include "mpi.h"
#include "pt4.h"

#include <vector>
#include <algorithm>

using namespace std;

void Solve()
{
    Task("MPI4Type18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	vector<int> a;
	if(rank == 0)
	{
		int N;
		pt >> N;
		int sz = (N * 3) * (N * (size - 1)/3);

		//vectorname.assign(int size, int value)
		a.assign(ptin_iterator<int>(sz), ptin_iterator<int>());
		
		vector<int> b(N);
		vector<int> d(N);
		
		for(int i = 0; i < N; i++)
		{
			b[i] = i + 1;
			d[i] = i * N * 3;
			Show(d[i]);
		}
		
		MPI_Datatype t;
	/*	
		int MPIAPI MPI_Type_indexed(
        int                   count, //块数和 array_of_blocklengths 和 array_of_displacements 参数中的元素数。
        _In_count_(count) int *array_of_blocklengths, //每个块的元素数。
        _In_count_(count) int *array_of_displacements, //每个单个块的位移（以字节为单位）。 所有块位移必须是旧类型参数中指定的数据类型范围的倍数。
        MPI_Datatype          oldtype,
 		_Out_ MPI_Datatype          *newtype
		);
	*/
		MPI_Type_indexed(N, &b[0], &d[0], MPI_INT, &t);
		MPI_Type_commit(&t);
		
		for(int i = 1, ds = 0; i < size; (i % 3!=0 ? ds += N : ds += N + 3*N*(N-1)), i++)
			MPI_Send(&a[ds], 1, t, i, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Status s;
		MPI_Probe(0, 0, MPI_COMM_WORLD, &s);
		
		int sz;
		MPI_Get_count(&s, MPI_INT, &sz);
		a.resize(sz);
		
		MPI_Recv(&a[0], sz, MPI_INT, 0, 0, MPI_COMM_WORLD, &s);
		copy(a.begin(),a.end(),ptout_iterator<int>());
	}
}
