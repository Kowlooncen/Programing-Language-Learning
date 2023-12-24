#include "mpi.h"
#include "pt4.h"

void Solve()
{
    Task("MPI5Comm32");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int sum = 0;
	int A;
	pt >> A;
	sum = A;
	
	int n = size / 2;
	int* sources = new int[n];
	int* degrees = new int[n];
	//get the number
	for(int i = 0; i < n; i++)
	{
		sources[i] = i;
	}
	//build a tree
	for(int i = 0; i < n; i++)
	{
		if(i == n-1 && size % 2 == 0)
			degrees[i] = 1;
		else if(i == n-1 && size % 2 == 1)
			degrees[i] = 2;
		else 
			degrees[i] = 2;
	}
	
	int x = 0;
	
	for(int i = 0; i < n; i++)
		x = x + degrees[i];
		
	int* destinations = new int[x];
	
	for(int i = 0; i < x; i++)
		destinations[i] = i + 1;
	
    for (int i = 0; i < n; i++)
    {
        Show(degrees[i]);
    }
    ShowLine();
    
    MPI_Comm comm;
    
	if(rank == 0)
		MPI_Dist_graph_create(MPI_COMM_WORLD, n, &sources[0], &degrees[0], &destinations[0], MPI_UNWEIGHTED, MPI_INFO_NULL, 0, &comm);
	else
		 MPI_Dist_graph_create(MPI_COMM_WORLD, 0, &sources[0], &degrees[0], &destinations[0], MPI_UNWEIGHTED, MPI_INFO_NULL, 0, &comm);
	
	int indegree, outdegree, w;
 	MPI_Dist_graph_neighbors_count(comm, &indegree, &outdegree, &w);

//	int WINAPI MPI_Dist_graph_neighbors(
//  _In_ MPI_Comm              comm,
//       _In_range_(>=,0)  int maxindegree,
//       _Out_writes_opt int   sources[],
//       _Out_writes_opt int   sourceweights[],
//       _In_range_(>=,0)  int maxoutdegree,
//       _Out_writes_opt int   destinations[],
//       _Out_writes_opt int   destweights[]
//);

	int* ns = new int[indegree];
	int* nd = new int[outdegree];
	
	MPI_Dist_graph_neighbors(comm, indegree, &ns[0], MPI_UNWEIGHTED, outdegree, &nd[0], MPI_UNWEIGHTED);
	
	for (int i = 0; i < indegree; i++)
	{
		MPI_Status s;
		int x;
		MPI_Recv(&x, 1, MPI_INT, ns[i], 0, comm, &s);
		sum += x;
	}
    
	for (int i = 0; i < outdegree; i++)
	{
		MPI_Send(&sum, 1, MPI_INT, nd[i], 0, comm);
	}

    pt << sum;
	
	
}
 	
	
	