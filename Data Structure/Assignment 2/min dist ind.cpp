#include<bits/stdc++.h>
using namespace std;
int distance(int b[],int n);

int distance(int b[],int n)
{
    int i,ne,sum[100],count=0,pos=0;
    int a[100];
    ///copy the element of b to a
    /// Finding the neighboring numbers distance
    for (i=0;i<n-1;i++)
    {
        a[i]=b[i];
        sum[i]=abs(a[i]-b[i+1]);
    }
    /// Finding the minimum distance
    int min=sum[0];
    for (i=1;i<n-1;i++)
    {
        if(min>sum[i])
            min=sum[i];
    }

    ///Finding the index number
    for (i=0;i<n-1;i++)
    {
        if(min==sum[i])
        {
        pos=i;
        return pos;
        }

    }
}
int main()
{
    int i,n;
    int b[100];
    cout<<"enter the size of array :";
    cin>>n;
    ///Taking the input of array b
    cout<<"Enter the element of array: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"index "<<i<<"= ";
        cin>>b[i];
    }
    cout<<"Minimum distance found at index "<<distance(b,n) <<endl;
    return 0;
}
