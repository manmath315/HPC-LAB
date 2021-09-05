#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array:";
	cin>>n;
	int arr[n],b,crr[n],i;
	for(i=0;i<n;i++){
		arr[i] = i;
	}
	cout<<"\nEnter scalar: ";
	cin>>b;
	omp_set_num_threads(n/3);
	#pragma omp parallel for shared(i)
	for(i=0;i<n;i++){
		crr[i] = arr[i] + b;
		printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
	}
    for(i=0; i<n; i++){
		printf("%d..%d + %d = %d\n", i, arr[i], b, crr[i]);
    }
	return 0;
}

