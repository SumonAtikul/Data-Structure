#include<bits/stdc++.h>
using namespace std;

#define SIZE 8

int a[SIZE] = {3, 7, 11, 9, 2, 4, 13, 15};

void quickSort(int lo, int hi);

int main()
{
    int i;

    //for(i = 0; i<SIZE; i++)
        //a[i]  =  rand() % 20;

    cout << "Array before sorting: ";
    for(i = 0; i<SIZE; i++)
        cout << a[i] << "  ";
    cout << endl;

    quickSort(0, SIZE-1);

	cout << "Array after sorting: ";
    for(i = 0; i<SIZE; i++)
        cout << a[i] << "  ";
    cout << endl;

    return 0;
}

void quickSort (int lo, int hi)
{
    int i = lo, j = hi;
    int pivot = a[ lo + (hi- lo) / 2 ];

    ///  partition
    do
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i < j);

    ///  recursion
    if (lo < j) quickSort(lo, j);
    if (i < hi) quickSort(i, hi);
}


