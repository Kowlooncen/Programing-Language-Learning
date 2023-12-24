#include "pt4.h"
#include "omp.h"
#include <cmath>
////////////////////////////////////////
///////////////////////////////////////
double Func_NoParallel(double x, int n)
{
	double result = 0;
	for(int i = 1; i <= n; i ++)
	{
		double sum = 0;
		for(int j = 1; j <= i + n; j++)
		{
			sum = sum + (j + log(1 + x + j)) / (2 * i * j - 1);
		}
		result = result + 1/sum;
	}
	return result;
}

double Func_Parallel(double x, int n)
{
	int count = 0;
	double result = 0;
	double sum = 0;
	
	#pragma omp parallel sections reduction(+:result)
	{
		#pragma omp section
		{
			double time = omp_get_wtime();

	        int num_procs = omp_get_num_procs();
	        int num_threads = omp_get_num_threads();
            ShowLine("num_procs: ", num_procs);
            ShowLine("num_threads: ", num_threads);

			 for (int i = 1; i <= n * (-2  + sqrt(10)) / 2; i++) 
			 {
				double sum = 0;
				for (int j = 1; j <= i + n; j++) {
					sum += (j + log(1 + x + j)) / (2 * i * j - 1);
					count++;
				}
				result += 1 / sum;
			}
			double p_time = omp_get_wtime() - time;
			Show("thread_num:", omp_get_thread_num());
	        Show("Count:", count);
	        ShowLine("Thread time:", p_time);
		}
		#pragma omp section
		{
			double time = omp_get_wtime();
			 for (int i = n * (-2  + sqrt(10)) / 2 + 1; i <= n; i++) 
			 {
				double sum = 0;
				for (int j = 1; j <= i + n; j++) {
					sum += (j + log(1 + x + j)) / (2 * i * j - 1);
					++count;
				}
				result += 1 / sum;
			}
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
    Task("OMPBegin10");
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