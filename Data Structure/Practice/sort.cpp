#include<bits/stdc++.h>
using namespace std;
int const SIZE=7;
int a[SIZE]= { 7,5,3,4,6,2,1 };

void insertionSort(int a[], int SIZE);

int main()
{
    insertionSort(a, SIZE);
    //printArray(a, SIZE);
    cout << "According to Insertion sort, sorted data is: ";
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
    return 0;
}
void insertionSort(int a[], int SIZE)
{
    int temp, pos;
    for (int i = 1; i < SIZE; i++)
    {
        temp = a[i];
        pos = i;
        while (pos > 0 && a[pos] > temp)
        {
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos + 1] = temp;
    }
}#include<bits/stdc++.h>
using namespace std;
int const SIZE=7;
int a[SIZE]= { 7,5,3,4,6,2,1 };

void insertionSort(int a[], int SIZE);

int main()
{
    insertionSort(a, SIZE);

    cout << "According to Insertion sort, sorted data is: ";
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
    return 0;
}
void insertionSort(int a[], int SIZE)
{
    int temp, pos;
    for (int i = 1; i < SIZE; i++)
    {
        temp = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > temp)
        {
            a[pos + 1] = a[pos];
            pos --;
        }
        a[pos + 1] = temp;
    }
}
