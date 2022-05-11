#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count = 0;
void swap(int *a,int *b){
	int t = *a;
	*a=*b;
	*b=t;
}
int partition(int * a,int low,int high){
	int pivot = a[high];
	int i = (low-1);
	for(int j =low ;j<=high-1;j++){
		if (a[j]<pivot){
			i=i+1;
			swap(&a[i],&a[j]);
			count++;
		}
	}
	swap(&a[i+1],&a[high]);
	count++;
	return i+1;
}
void quick_sort(int *a,int low,int high){
	if(low<high){
		int q = partition(a,low,high);
		quick_sort(a,low,q-1);
		quick_sort(a,q+1,high);
		count++;
	}
}



int main(){
	ofstream outf;
	ifstream inf;
	clock_t st,end;
	double etime;
	int n=10;
	int *a;
//	cout<<"Enter n"<<endl;
//	cin>>n;
	st=clock();
	a=new int[n];
	srand((long int)clock());
	
	outf.open("QuickSort_IN.txt");
	for(int i=1;i<=n;i++){
		outf<<rand()%50<<"\t";
	}
	outf.close();
	
	inf.open("QuickSort_IN.txt");
	for(int i=1;i<=n;i++){
		inf>>a[i];
	}
	inf.close();
	
	cout<<endl;
	cout<<"Before Sorting"<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<"\t";
	}
	count =0;
	quick_sort(a,1,n);
	cout<<endl;
	cout<<"After Sorting"<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<"\t";
	}
	outf.open("QuickSort_OUT.txt");
	for(int i=1;i<=n;i++){
		outf<<a[i]<<"\t";
	}
	outf.close();
	end=clock();
	
	etime = ((double)(end-st))/CLOCKS_PER_SEC;
	cout<<"\n\nQUICK SORT:"<<endl;
	cout<<"Total Active Operations:"<<count<<endl;
	cout<<"Execution time:"<<etime<<endl;
	delete(a);
	return 0;
}