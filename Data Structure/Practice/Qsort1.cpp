#include<bits/stdc++.h>
using namespace std;

#define SIZE 8
int a[SIZE] = {7, 9, 8, 0, 2, 3, 8, 9};
void quickSort(int lo, int hi);
int main()
{
    int i;
    quickSort(0, SIZE-1);
    for(int i=0; i<SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

void quickSort(int lo, int hi)
{
    int i=lo, j=hi;
    int pivot=a[lo+(hi-lo)/2];
    do
    {
       while(a[i] < pivot) i++;
       while(a[j] > pivot) j--;
       if(i<=j)
       {
           swap(a[i], a[j]);
           i++;
           j--;
       }

    }while(i<j);
    if (lo < j) quickSort(lo, j);
    if (i < hi) quickSort(i, hi);
}
