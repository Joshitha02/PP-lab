#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){

    MPI_Init(NULL,NULL);
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);

    int send_data=world_rank;
    int recv_data[world_size];

    MPI_Gather(&send_data,1,MPI_INT,recv_data,1,MPI_INT,0,MPI_COMM_WORLD);

    if(world_rank==0){
        printf("\n Gathered data \n")
        for(int i=0;i<world_size;i++){
            printf(" %d \t",recv_data[i]);
        }
    }

    MPI_Finalize();
    return 0;
}    
