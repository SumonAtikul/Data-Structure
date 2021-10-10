#include<bits/stdc++.h>
using namespace std;
void minDistance(int a[], int n);
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *a;
    a = new int[n];
    cout << "Enter the elements: ";
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    minDistance(a, n);
}
void minDistance(int a[], int n)
{
    int index = 0, minDis = 10000000;
    for(int i = 0; i<n; i++)
    {
        if(abs(a[i] - a[i+1]) < minDis)
        {
            minDis = abs(a[i] - a[i+1]);
            index = i;
        }
    }
    cout << "Index: " << index << endl;
}

