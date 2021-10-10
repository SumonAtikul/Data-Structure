#include<bits/stdc++.h>
using namespace std;

void spiralOrder(int** a, int r, int c);

int main()
{
    int r, c;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    int** arr;

    arr = new int*[r];

    for(int i = 0; i<r; i++)
    {
        arr[i] = new int[c];
    }

    cout << "Enter the elements" << endl;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cin >> arr[i][j];
        }
    }

    spiralOrder(arr, r, c);

    for(int i = 0; i<r; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;

}

void spiralOrder(int** a, int r, int c)
{
    int T = 0, B = r-1, L = 0, R = c-1;

    int dir = 0;

    cout << endl << endl;

    cout << "Original Array:" << endl;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;


    cout << "Elements in spiral order: ";

    while(T<=B && L<=R)
    {
        if(dir == 0)
        {
            for(int i = L; i<=R; i++)
            {
                cout << a[T][i] << " ";
            }
            T++;
            dir = 1;
        }

        else if(dir == 1)
        {
            for(int i = T; i<=B; i++)
            {
                cout << a[i][R] << " ";
            }
            R--;
            dir = 2;
        }

        else if(dir == 2)
        {
            for(int i = R; i>=L; i--)
            {
                cout << a[B][i] << " ";
            }
            B--;
            dir = 3;
        }

        else if(dir == 3)
        {
            for(int i = B; i>=T; i--)
            {
                cout << a[i][L] << " ";
            }
            L++;
            dir = 0;
        }
    }

    cout << endl;
}


