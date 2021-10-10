#include<bits/stdc++.h>
using namespace std;
double getMean(double *a, int n)
{
    double sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
    }
    return sum/n;
}
double getMedian(double *a, int n)
{
    sort(a,a+n);
    if(n%2!=0){
        return a[n/2];
    }
    else{
        return (a[n/2]+a[n/2-1])/2.0;
    }
}
double getMode(double *a, int n)
{
     sort(a,a+n);
     double element=0;
     int cnt=0;
     for(int i=0; i<n; i++){
        double tempelement=a[i];
        double tempcnt=0;
        for(int j=0; j<n; j++){
            if(a[j]==tempelement){
                tempcnt++;
            }
            if(tempcnt>cnt){
                cnt=tempcnt;
                element=tempelement;
            }
        }
     }
     return element;
}
int main()
{
    int n;
    double a[105];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Mean: "<<getMean(a,n)<<endl;
    cout <<"Median: "<<getMedian(a,n)<<endl;
    cout<<"Mode: "<<getMode(a,n)<<endl;

    return 0;
}



