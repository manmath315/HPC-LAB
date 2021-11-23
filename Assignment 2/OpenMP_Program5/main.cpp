#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

void display(int a[],int b[],int c[],int n){
	cout<<"Result of addition \na[i]  +  b[i] = c[i]\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  +  "<<b[i]<<" = "<<c[i]<<"\n";
}

int main()
{
	int n;
	cout<<"Enter no of eleemnts in array: ";
	cin>>n;
	int a[n],b[n],c[n],i;
	
	for(i=0;i<n;i++){
		a[i] = i;
		b[i] = i + 50;
	}
	
	#pragma omp parallel for firstprivate(a,b) shared(c) num_threads(n/2)
	for(i=0;i<n;i++)
	{
		c[i] = a[i] + b[i];
		printf("Thread %d works on element %d\n", omp_get_thread_num(), i);
	}
	
	display(a,b,c,n);
	return 0;
}

