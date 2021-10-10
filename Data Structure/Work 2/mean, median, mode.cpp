#include<bits/stdc++.h>
using namespace std;
double mean(double arr[], int n){
    double sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum/n;
}
double median(double arr[], int n){
    sort(arr, arr+n);
    if(n%2==0){
        return (arr[n/2-1]+arr[n/2])/2;
    }
    else{
        return arr[n/2];
    }
}
double mode(double arr[], int n){
    double count[105]={0};
    for(int i=0; i<n; i++){
            count[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(count[i]>1){
                return count[i];
        }
    }
    ///return count[i];
}
int main()
{
    int n;
    double arr[105];
    cout<<"Enter the size of array: ";
    cin >> n;
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Mean: "<<mean(arr, n);
    cout<<"\nMedian: "<<median(arr, n);
    cout<<"\nMode: "<<mode(arr, n);
}
