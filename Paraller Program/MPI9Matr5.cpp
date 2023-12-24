#include "mpi.h"
#include "pt4.h"

#include <cmath>

int k;              // number of processes
int r;              // rank of the current process

int m, p, q;        // sizes of the given matrices
int na, nb;         // sizes of the matrix bands

int *a_, *b_, *c_;  // arrays to store matrices in the master process
int *a, *b, *c;     // arrays to store matrix bands in each process

int Cal(int ai, int bj, int x) {
	int res = 0;
	int st = (x + r) * nb;
	if (st >= nb * k) {
		st -= nb * k;
		st = (st / nb) * nb;
	}
	for (int i = 0; i < nb; ++i) {
		if (st + i >= p) {
			break;
		}
		res += a[p * ai + st + i] * b[q * i + bj];
	}
	return res;
}

void MatrCalc(int x)
{
	int sz = nb * q;
	for (int i = 0; i < na; i++) 
	{
		for (int j = 0; j < q; j++) 
		{
			c[q * i + j] = c[q * i + j] + Cal(i, j, x);
		}
	}
	MPI_Status s;

	MPI_Sendrecv_replace(b, sz, MPI_INT, r == 0 ? k - 1 : (r - 1) % k, 0, (r + 1) % k, 0, MPI_COMM_WORLD, &s);
}

void Solve()
{
    Task("MPI9Matr5");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    k = size;
    r = rank;

	pt >> na >> p >> nb >> q;
	int sz1 = na * p,
		sz2 = nb * q,
		sz3 = na * q;
	a = new int[sz1];
	b = new int[sz2];
	c = new int[sz3];
	for (int i = 0; i < sz1; ++i) {
		pt >> a[i];
	}
	for (int i = 0; i < sz2; ++i) {
		pt >> b[i];
	}
	for (int i = 0; i < sz3; ++i) {
		pt >> c[i];
	}
	int L;
	pt >> L;
	for(int i = 0; i < L; i++)
	{
		MatrCalc(i);
	}
	
	for (int i = 0; i < sz3; ++i) {
		pt << c[i];
	}
	for (int i = 0; i < sz2; ++i) {
		pt << b[i];
	}
}
