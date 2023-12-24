#include <iostream>
#include <math.h>
#include <time.h>
#include <sstream>
#include "pt4.h"
#include "omp.h"
/////////////////////////////
using namespace std;

double Func_NoParallel(double x, int n)
{
	double result = 0;
	for (int i = 1; i <= n; ++i) {
		double sum = 0;
		for (int j = 1; j <= i; ++j) {
			sum += (j + pow((x + j), 0.25)) / (2 * i * j - 1);
		}
		result += 1 / sum;
	}
	return result;
}

double Func_Parallel(double x, int n)
{
	int k1, k2, k3;
	double result = 0;
	int count = 0;
	int k = 0;
	for (int i = 1; i <= n; ++i)
		k = k + i;
	int a = 0;
	int b = 0;
	for (int i = 1; i <= n; ++i) 
	{
		a = a + i;
		if (a > k / 4) 
		{
			if (b == 0) k1 = i;
			else if (b == 1) k2 = i;
			else {
				k3 = i;
				break;
			}
			b++;
			a = 0;
		}
	}
	#pragma omp parallel sections reduction(+:result)
	{
		#pragma omp section
		{
			double time = omp_get_wtime();
			
			int num_procs = omp_get_num_procs();
	        int num_threads = omp_get_num_threads();
            ShowLine("num_procs: ", num_procs);
            ShowLine("num_threads: ", num_threads);
            
			double res1 = 0;
			double sum = 0;
			 for (int i = 1; i <= k1; ++i) 
			 {
				sum = 0;
				for (int j = 1; j <= i; ++j) {
					sum += (j + pow((x + j), 0.25)) / (2 * i * j - 1);
					count++;
				}
				res1 += 1 / sum;
			}
			result = result + res1;
			double p_time = omp_get_wtime() - time;
			Show("thread_num:", omp_get_thread_num());
	        Show("Count:", count);
	        ShowLine("Thread time:", p_time);
		}
		#pragma omp section
		{
			double time = omp_get_wtime();
			double res2 = 0;
			double sum;
			 for (int i = k1 + 1; i <= k2; ++i) 
			 {
				sum = 0;
				for (int j = 1; j <= i; ++j) {
					sum += (j + pow((x + j), 0.25)) / (2 * i * j - 1);
					count++;
				}
				res2 += 1 / sum;
			}
			result = result + res2;
			double p_time = omp_get_wtime() - time;
			Show("thread_num:", omp_get_thread_num());
	        Show("Count:", count);
	        ShowLine("Thread time:", p_time);
		}
		#pragma omp section
		{
			double time = omp_get_wtime();
			double res3 = 0;
			double sum;
			 for (int i = k2 + 1; i <= k3; ++i) 
			 {
				sum = 0;
				for (int j = 1; j <= i; ++j) {
					sum += (j + pow((x + j), 0.25)) / (2 * i * j - 1);
					count++;
				}
				res3 += 1 / sum;
			}
			result = result + res3;
			double p_time = omp_get_wtime() - time;
			Show("thread_num:", omp_get_thread_num());
	        Show("Count:", count);
	        ShowLine("Thread time:", p_time);
		}
		#pragma omp section
		{
			double time = omp_get_wtime();
			double res4 = 0;
			double sum;
			 for (int i = k3 + 1; i <= n; ++i) 
			 {
				sum = 0;
				for (int j = 1; j <= i; ++j) {
					sum += (j + pow((x + j), 0.25)) / (2 * i * j - 1);
					count++;
				}
				res4 += 1 / sum;
			}
			result = result + res4;
			double p_time = omp_get_wtime() - time;
			Show("thread_num:", omp_get_thread_num());
	        Show("Count:", count);
	        ShowLine("Thread time:", p_time);
		}
	}
	return result;
}

void Solve()
{
    Task("OMPBegin13");

	double x;
	int n;
	pt >> x >> n;
	double start = omp_get_wtime();
	double ans = Func_NoParallel(x, n);
    double time = omp_get_wtime() - start;
    ShowLine("Non-parallel time: ", time);
	pt << ans;
	
///////////////////////////////////////////////////////////////
	
	pt >> x >> n;
	start = omp_get_wtime();
	ans = Func_Parallel(x, n);
	double p_time = omp_get_wtime() - start;
    ShowLine("Parallel time: ", p_time);
	pt << ans;
	ShowLine("Rate: ", time / p_time);
}

