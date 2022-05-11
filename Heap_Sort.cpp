#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
long int count = 0;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Left(int i)
{
	return 2 * i;
}
int Right(int i)
{
	return (2 * i) + 1;
}

void max_heapify(int *a, int i, int n)
{
	int largest = i;
	int l = Left(i);
	int r = Right(i);

	if (l <= n && a[l] > a[i])
	{ 
		largest = l;
	}
	
	if (r <= n && a[r] > a[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(a[i], a[largest]);
		max_heapify(a, largest, n);
	}
}

void build_max_heap(int *a, int n)
{
	for (int i = n ; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}

void heap_sort(int *a, int n)
{
	build_max_heap(a, n);
	for (int i = n; i >= 2; i--)
	{
		swap(a[1], a[i]);
		n -= 1;
		max_heapify(a, 1, n);
	}
}

int main()
{
	ofstream outf;
	ifstream inf;
	clock_t st, end;
	double etime;
	int n = 12;
	int *a;
	//	cout<<"Enter n"<<endl;
	//	cin>>n;
	st = clock();
	a = new int[n];
	srand((long int)clock());

	outf.open("HeapSort_IN.txt");
	for (int i = 1; i <= n; i++)
	{
		outf << rand() % 50 << "\t";
	}
	outf.close();

	inf.open("HeapSort_IN.txt");
	for (int i = 1; i <= n; i++)
	{
		inf >> a[i];
	}
	inf.close();

	cout << endl;
	cout << "Before Sorting" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << "\t";
	}
	count = 0;

	heap_sort(a, n);

	cout << endl;
	cout << "After Sorting" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << "\t";
	}
	outf.open("HeapSort_OUT.txt");
	for (int i = 1; i <= n; i++)
	{
		outf << a[i] << "\t";
	}
	outf.close();
	end = clock();

	etime = ((double)(end - st)) / CLOCKS_PER_SEC;
	cout << "\n\nHEAP SORT:" << endl;
	cout << "Total Active Operations:" << count << endl;
	cout << "Execution time:" << etime << endl;
	delete (a);
	return 0;
}