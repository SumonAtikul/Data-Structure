/******************
*	Assignment-3									*
*	============									*
*													*
*	Prepared By:									*
*	1.Md. Mahdi Hossain Hira						*
*	2.Ahshanul Haque Chowdhury 						*
*	3.Md. Akikul Islam Sumon						*
*	4.Md. Ashfaqur Rahman                           *
*	5.MD. Ashikur Rahman Tushar						*
*													*
*	Date of Submission:28-11-2020 					*
*******************/

#include <bits/stdc++.h>
using namespace std;


const int n = 56;


struct Student{
    string name, id;
    int marks;
} s[n];


void struct_sort();
bool operator > (Student &x, Student &y);

int main()
{
    int i;
    string t;

    freopen("input.txt", "r", stdin);

    for(i=0; i<n; i++)
    {
        getline(cin, s[i].id);
        getline(cin, s[i].name);
        getline(cin, t);
        s[i].marks = atoi(t.c_str());
    }

    struct_sort();

    for(i=0; i<n; i++)
    {
        cout << setw(15); cout << left << s[i].id;
        cout << setw(30); cout << s[i].name;
        cout << setw(5);  cout << s[i].marks << endl;
    }
    return 0;
}

bool operator < (Student &x, Student &y)
{
    if(x.marks < y.marks) return true;
    if(x.marks == y.marks && x.id > y.id) return true;
    return false;
}

void struct_sort()
{
    Student temp;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<n-i; j++){
            if(s[j-1] < s[j]){
                temp = s[j-1];
                s[j-1] = s[j];
                s[j] = temp;
            }
        }
    }
}
