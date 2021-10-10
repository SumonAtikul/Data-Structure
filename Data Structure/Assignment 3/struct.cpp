#include<bits/stdc++.h>
using namespace std;

struct student
{
    int roll_no,marks;
    char name[25];
}stud[100],t;
bool compare(student a, student b){
    return a.marks<b.marks;
}

int main()
{
    int i,j,n;
    cout<<"Enter the no of students" << endl;
    scanf("%d",&n);
    cout<<"enter student info as roll_no , name , marks" << endl;
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d",&stud[i].roll_no,stud[i].name,&stud[i].marks);
    }
    for(int i=0; i<n; i++){

    sort compare(stud,n+1,compare);
    }

    printf("\nStudent info in terms of marks from highest to lowest\n");
    printf("\nROLL_NO\t\tNAME\t\tMARKS\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\n",stud[i].roll_no,stud[i].name,stud[i].marks);
    }
}
