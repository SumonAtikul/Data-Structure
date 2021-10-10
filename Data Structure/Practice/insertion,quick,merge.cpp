#include<bits/stdc++.h>
using namespace std;
const int  n = 7;
int a[n]={7,5,3,4,6,2,1};

void insertionSort(int a[],int n)
{
    int i, temp, pos;
    for(i=1; i < n; ++i)
    {
        temp = a[i];
        pos = i;
        while(pos >0 && a[pos-1] > temp){
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos] = temp;
    }

}

void Merge(int left[],int nL, int right[],int nR, int A[])
{
    int i = 0,j = 0,k = 0;

    while (i < nL && j < nR)
    {
        if(left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < nL)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < nR)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int a[],int n)
{
    int mid, i;
    if (n < 2){
        return;
    }

    mid = n/2;
    int left[mid], right[n-mid];
    for (i = 0; i <= mid-1; i++){
        left[i] = a[i];
    }

    for (i = mid; i <= n-1; i++){
        right[i-mid]= a[i];
    }

    MergeSort(left, mid);
    MergeSort(right, n-mid);
    Merge(left, mid, right, n-mid, a);
}

void quicksort(int lo,int hi)
{
    int i = lo, j = hi;
    int pivot = a[ lo + ( hi - lo ) / 2 ];
    while(i<j)
    {
        while( a[i] < pivot ) i++;
        while( a[j] > pivot ) j--;
        if(i<=j)
        {
            swap( a[i], a[j]);
            i++;
            j--;
        }
    }

    if(lo < j) quicksort( lo, j);
    if(i < hi) quicksort( i, hi);

}

int main()
{
    int num;
    do
    {
        cout << "Press 1: " << "Insertion Sort" << endl;
        cout << "Press 2: " << "Merge Sort" << endl;
        cout << "Press 3: " << "Quick Sort" << endl;
        cout << "Press 4: " << "Exit" << endl;
        cout << "Choose your option: ";
        scanf("%d", &num);
        switch(num)
        {
        case 1:
            insertionSort(a,n);
            printf ("According to InsertionSort, sorted data is: ");
            for(int i = 0; i < n; i++){
                printf(" %d",a[i]);
            }
            cout << endl;
            break;

        case 2:
            MergeSort(a,n);
            printf ("According to Merge Sort, sorted data is: ");
            for(int i = 0; i < n; i++){
                printf (" %d",a[i]);
            }
            cout << endl;
            break;

        case 3:
            quicksort(0,n-1);
            printf ("According to Quick Sort, sorted data is: ");

            for(int i = 0; i < n; i++){
                printf (" %d",a[i]);
            }
            cout << endl;
            break;
        case 4:
            printf ("Program terminated.");
            break;
        }
    }
    while(num != 4);


    return 0;
}
