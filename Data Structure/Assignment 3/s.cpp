#include<bits/stdc++.h>
using namespace std;
struct student{
    string name, id;
    int marks;
}s[105];
bool compare(student a, student b){
    return a.marks>b.marks;
}
int main(){
    string t;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        getline(cin, s[i].id);
        getline(cin, s[i].name);
        getline(cin, t);
    }
    sort(s,s+n,compare);
    for(int i=0; i<n; i++){
        cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].marks<<endl;
    }
    ///bool compare(student x, student y){
        ///if(x.marks==y.marks){
            ///return x.id<y.id;
        ///}
        ///return x.marks>y.marks;
    ///}
}
