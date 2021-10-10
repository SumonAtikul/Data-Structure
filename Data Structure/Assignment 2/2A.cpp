#include <bits/stdc++.h>
using namespace std;

int min_dist(int *arr, int n, int x, int y)
{
    int i, j;
    int min_dist = INT_MAX;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if( (x == arr[i] && y == arr[j] ||
                y == arr[i] && x == arr[j]) &&
                min_dist > abs(i-j))
            {
                min_dist = abs(i-j);
            }
        }
    }
    return min_dist;
}
int main()
{
    int n,x,y;
    int arr[50];
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the X: ";
    cin>>x;
    cout<<"Enter the Y: ";
    cin>>y;


    cout << "Minimum distance between " << x <<" and " << y << " is " <<
                    min_dist(arr, n, x, y) << endl;
}



