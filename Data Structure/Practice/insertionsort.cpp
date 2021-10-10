#include<bits/stdc++.h>
using namespace std;
int const SIZE=5;
int a[SIZE]= {6, 5, 7, 2, 1};

void insertionSort(int a[], int SIZE);
int main()
{
        insertionSort(a, SIZE);

        cout << "after sorting: ";
        for (int i = 0; i < SIZE; i++)
        {
            cout << a[i] << " ";
        }
        return 0;
}

void insertionSort(int a[], int SIZE)
{
        int TEMP, pos;
        for (int i = 1; i < SIZE; i++)
        {
            TEMP = a[i];
            pos = i - 1;
            while (pos >= 0 && a[pos] > TEMP)
            {
                a[pos + 1] = a[pos];
                pos --;
            }
            a[pos + 1] = TEMP;
        }
}
