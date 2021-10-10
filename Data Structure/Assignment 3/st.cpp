#include<bits/stdc++.h>
using namespace std;
struct student_information{
    string name;
    int id, marks;
};
bool compare(student_information x, student_information y){
            if(x.marks == y.marks){
                return x.id<y.id;
            }
            return x.marks>y.marks;
}
int main(){
    student_information st[105];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>st[i].id>>st[i].name>>st[i].marks;
    }
    sort(st,st+n,compare);
    for(int i=0; i<n; i++){
        cout<<st[i].id<<" "<<st[i].name<<" "<<st[i].marks<<endl;

        }
        return 0;
    }

