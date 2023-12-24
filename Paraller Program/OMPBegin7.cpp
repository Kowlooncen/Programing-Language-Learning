#include <iostream>
#include <math.h>
#include <time.h>
#include <sstream>
#include "pt4.h"
#include "omp.h"
////////////////////////////////////////////
using namespace std;

double Func_NoParallel(double x, int n)
{
	double result = 0;
	for(int i = 1; i <= n; i++)
	{
		double sum = 0;
		for(int j = i; j <= n; j++)
			sum = sum + (j + sin(x + j)) / (2.0 * i * j - 1.0);
		result = result + 1/sum;
	}
	return result;
}

double Func_Parallel(double x, int n)
{
    double result = 0;
    
#pragma omp parallel num_threads(4) reduction(+:result)
    {
        int num = omp_get_thread_num();
        int num_procs = omp_get_num_procs();
        int num_threads = omp_get_num_threads();
        int count = 0;
        if (num == 0)
        {
            ShowLine("num_procs: ", num_procs);
            ShowLine("num_threads: ", num_threads);
        }
		double sum = 0;
        double time = omp_get_wtime();
        int a, b;
        for (int i = 1; i <= n; i += 8) 
		{
			a = i + num;
			sum = 0;
			for (int j = a; j <= n; ++j) 
			{
				sum += (j + sin(x + j)) / (2 * a * j - 1);
				count++;
			}
			result += 1 / sum;
			
			b = i + 7 - num;
			sum = 0;
			for (int j = b; j <= n; ++j) 
			{
				sum += (j + sin(x + j)) / (2 * b * j - 1);
				count += 1;
			}
			result += 1 / sum;
		}
        double p_time = omp_get_wtime() - time;
        Show("thread_num:", num);
        Show("Count:", count);
        ShowLine("Thread time:", p_time);
    }
    return result;
}

void Solve()
{
	Task("OMPBegin7");
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


