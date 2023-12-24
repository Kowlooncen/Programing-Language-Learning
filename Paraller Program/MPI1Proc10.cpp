#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI1Proc10");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int N;
    if(rank == 0&&size %2 == 0)
    {
    	pt >> N;
		int k = 0;
		double min = 0;
		for(int i = 0; i < N; i++)
	    {
	    	double a; 
			pt >> a;
			if(k == 0)	
			{
				min = a;
				k = 1;
			}
			else
			{
				if(min > a)
				{
					min = a;
				}
			}
		}
		pt << min;
	}
    else if(rank == 0&&size %2 != 0)
    {
    	pt >> N;
		int k = 0;
		int min = 0;
		for(int i = 0; i < N; i++)
	    {
	    	int a; 
			pt >> a;
			if(k == 0)	
			{
				min = a;
				k = 1;
			}
			else
			{
				if(min > a)
				{
					min = a;
				}
			}
		}
		pt << min;
	}
	else if(rank >= 2 && rank % 2 == 0)
	{
		pt >> N;
		int k = 0;
		int min = 0;
		for(int i = 0; i < N; i++)
	    {
	    	int a; 
			pt >> a;
			if(k == 0)	
			{
				min = a;
				k = 1;
			}
			else
			{
				if(min > a)
				{
					min = a;
				}
			}
		}
		pt << min;
	}
	else{
		pt >> N;
		int k = 0;
		double max = 0;
		for(int i = 0; i < N; i++)
	    {
	    	double a; 
			pt >> a;
			if(k == 0)	
			{
				max = a;
				k = 1;
			}
			else
			{
				if(max < a)
				{
					max = a;
				}
			}
		}
		pt << max;
	}

}
