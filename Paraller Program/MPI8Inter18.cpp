#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI8Inter18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int a[size/2], a0,a1;
    int root;
    
    MPI_Comm inter;
    MPI_Comm_get_parent(&inter);
    
    if (inter == MPI_COMM_NULL){
        MPI_Comm_spawn("ptprj.exe", NULL, size, MPI_INFO_NULL, 0, MPI_COMM_WORLD,&inter, MPI_ERRCODES_IGNORE);
        for(int i=0;i<size/2;i++) pt>>a[i];
        root=0;
    }
    else root=MPI_ROOT;
    
    MPI_Comm comm;
    int local_rank;
    MPI_Comm_rank(inter,&local_rank);
    MPI_Comm_split(inter,local_rank%2,rank,&comm);
    
    int new_rank;
    MPI_Comm_rank(comm,&new_rank);
    if(local_rank%2==0) MPI_Reduce_scatter_block(a,&a0,1,MPI_INT,MPI_MIN,comm);
    else MPI_Reduce_scatter_block(a,&a0,1,MPI_INT,MPI_MAX,comm);
    if (root == MPI_ROOT) {
        Show(a0); 
    }
    
    

}
