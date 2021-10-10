#include<bits/stdc++.h>
using namespace std;
int min_dis(int *a,int n,int x,int y);
int main()
{
    int n,x,y;
    int a[50];
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the X: ";
    cin>>x;
    cout<<"Enter the Y: ";
    cin>>y;

    cout<<"Minimum distance: "<<min_dis(a,n,x,y)<<endl;
    return 0;
}

int min_dis(int *a,int n,int x,int y)
{
   int min_dis;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(x==a[i]&&y==a[j]||y==a[i]&&x==a[j]&&min_dis>abs(i-j))
           {
               min_dis=abs(i-j);
           }
       }
   }
   return min_dis;
}
