#include <bits/stdc++.h>
using namespace std;
int find_index(int a[],int n)
{
    int idx=0,min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(i)
        {
            if(abs(a[i]-a[i-1])<min)
            {
                min=abs(a[i]-a[i-1]);
                idx=i-1;
            }
        }
    }
    return idx;
}
int main ()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the array of elements: ";
    int a[n+2];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Index: "<<find_index(a,n)<<endl;

}
