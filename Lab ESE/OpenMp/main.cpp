#include <omp.h>
#include <stdio.h>

void barrier_demo(){
	printf("\n\n==========Exapmle of Barrier========\n");
	int arr[10], i;
    #pragma omp parallel num_threads(5)
    {
        #pragma omp for
        for (i = 0; i < 5; i++)
            arr[i] = i * i;
		printf("Barrier is called by %d thread\n",omp_get_thread_num());
        #pragma omp barrier
		
        #pragma omp for
        for (i = 0; i < 5; i++)
            printf("arr[%d]= %d, Executed by %d thread\n",i,arr[i],omp_get_thread_num());
    }
}

void order_demo(){
	printf("\n\n==========Exapmle of Barrier========\n");
	#pragma omp parallel num_threads(5)
    {
        #pragma omp for ordered
        for (int i = 0; i < 5; i++){
        	for(int j=0;j<5;j++){
        		printf("%d is printed by %d thread\n",j,omp_get_thread_num());	
			}
			printf("\n\n");
		}
               
    }
	
}

void single_demo() {
	printf("\n\n==========Exapmle of Single========\n");
   #pragma omp parallel num_threads(5)
   {
      #pragma omp single
      printf("Single thread execute the line\n");

      printf("Multiple thread execute the line\n");
    }
}

int main() {
	single_demo();
	barrier_demo();
	order_demo();
}
