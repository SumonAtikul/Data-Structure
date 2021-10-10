#include<bits/stdc++.h>
using namespace std;
double mean(double *a,int n)
{
    double sum=0;
    for(int i=0;i<n;i++)

        sum+=a[i];

    return sum/n;
}
double median(double *a,int n)
{

    sort(a,a+n);
    if(n%2!=0)
    {
        return a[n/2];
    }
    else {
        return (a[n/2]+a[n/2-1])/2.0;
    }
}
double mode(double *a,int n)
{
    sort(a,a+n);
    double element=0;
    int count=0;
    for(int j=0;j<n;j++){

        double tempelement =a[j];
        double tempcount=0;
        for(int p=0;p<n;p++)
            if(a[p]==tempelement)
            tempcount++;
        if(tempcount>count)
        {
            count=tempcount;
            element=tempelement;
            ///count=tempcount;
        }


  }
  return element;
}

    int main()
{

    int n;
    double a[50];
    cout<<"enter the size of array: ";
    cin>>n;
    cout<<"enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"mean="<<mean(a,n)<<endl;
    cout <<"median="<<median(a,n)<<endl;
    cout<<"mode="<<mode(a,n)<<endl;


    return 0;
}
