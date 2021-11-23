#include "mpi.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    int world_rank,world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    float arr[5]={1.1,2.2,3.3,4.4,5.5};
    float brr[5]={0.0,0.0,0.0,0.0,0.0};
    if (world_rank == 0) {
        MPI_Send(&arr, 5, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&brr, 5, MPI_FLOAT, 0, 0, MPI_COMM_WORLD,
                MPI_STATUS_IGNORE);
        for(int i=0;i<5;i++){
            cout<<"brr["<<i<<"] = "<<brr[i]<<"\n";
        }
    }   
}
