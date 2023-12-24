#include "pt4.h"
#include "omp.h"
#include "cmath"
#include <ctime>
#define NUM_THREADS 2
//////////////////////////////////
/////////////////////////////////

using namespace std;

double func_one(double x, int n)
{
	double sum1 = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= 2*n; j++)
			sum1 = sum1 + (j + pow(x + j, 1.0 / 3 )) / (2 * i*j - 1);
		sum = sum + 1/sum1;
		sum1 = 0;
	}
	return sum;
}

double func_mul(double x, int n)
{
	omp_set_num_threads(NUM_THREADS);
	double sum1 = 0;
	double sum = 0;
#pragma omp parallel private(sum1) shared(x, n) reduction(+:sum)
	{
		int num = omp_get_thread_num();
        int num_procs = omp_get_num_procs();
        int num_threads = omp_get_num_threads();
        int count = 0;
        if (num == 0)
        {
            ShowLine("\nnum_procs: ", num_procs);
            ShowLine("num_threads: ", num_threads);
        }
		double t = omp_get_wtime();
		for(int i = num + 1; i <= n; i = i+2)
		{
			sum1 = 0;
			for(int j = i; j <= 2*n; j++)
			{
				sum1 = sum1 + (j + pow(x + j, 1.0 / 3)) / (2 * i*j - 1);
				count += 1;
			}
			sum = sum + 1/sum1;
		}
		Show("\nthread_num:");
		Show(num);
		Show("Count:");
		Show(count);
		Show("Thread time:");
		Show(omp_get_wtime() - t);
	}
	return sum;
}

void Solve()
{
    Task("OMPBegin4");
	int n;
	double x;
	pt >> x >> n;
	double start = omp_get_wtime();
	double ans = func_one(x, n);
	Show("Non-parallel time:");
	double time = omp_get_wtime()-start;
	Show(time);
	pt << ans;

	start = omp_get_wtime();
	pt >> x >> n;
	start = omp_get_wtime();
	double sum;
	sum = func_mul(x, n);
	double p_time = omp_get_wtime() - start;
	Show("\nParallel time::");
	Show(p_time);
	pt << sum;
	ShowLine("\nRate: ", time / p_time);
}


