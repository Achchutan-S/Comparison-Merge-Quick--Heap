#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
long int count = 0;

void merge(int *a, int lb, int mid, int ub)
{
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int *L, *R;
    L = new int[n1 + 1];
    R = new int[n2 + 1];

    for (int i = 1; i <= n1; i++)
    {
        L[i] = a[lb + i - 1];
    }
    for (int j = 1; j <= n2; j++)
    {
        R[j] = a[mid + j];
    }

    L[n1 + 1] = INT16_MAX;
    R[n2 + 1] = INT16_MAX;
    int i = 1, j = 1;
    // for(int k=lb; k<=ub;k++){
    //     if(L[i]<=R[j]){
    //         a[k]=L[i];
    //         i++;
    //     }
    //     else{
    //         a[k]=R[j];
    //         j++;
    //     }
    // }

    int k = lb;

    while (k <= ub)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i< n1+1){
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2+1){
        a[k]=R[j];
        j++;
        k++;
    }
    
}

void merge_sort(int *a, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    ofstream outf;
    ifstream inf;
    clock_t st, end;
    double etime;
    int n = 10;
    int *a;
    //	cout<<"Enter n"<<endl;
    //	cin>>n;
    st = clock();
    a = new int[n];
    srand((long int)clock());

    outf.open("MergeSort_IN.txt");
    for (int i = 1; i <= n; i++)
    {
        outf << rand() % 50 << "\t";
    }
    outf.close();

    inf.open("MergeSort_IN.txt");
    for (int i = 1; i <= n; i++)
    {
        inf >> a[i];
    }
    inf.close();

    cout << "\n";
    cout << "Before Sorting" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\t";
    }

    merge_sort(a,1,n);
    cout << "\n";
    cout << "After Sorting" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\t";
    }
    outf.open("MergeSort_OUT.txt");
    for (int i = 1; i <= n; i++)
    {
        outf << a[i] << "\t";
    }
    outf.close();
    end = clock();

    etime = ((double)(end - st)) / CLOCKS_PER_SEC;
    cout << "\n\nMERGE SORT:";
    cout << "Total Active Operations:" << count << endl;
    cout << "Execution time:" << etime << endl;
    delete (a);
    return 0;
}