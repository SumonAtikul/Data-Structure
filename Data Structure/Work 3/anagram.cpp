#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str1[1000], str2[1000];
    int len1, len2;
    cout<<"Enter first string ";
    gets(str1);
    cout<<"Enter second string ";
    gets(str2);
    len1=strlen(str1);
    len2=strlen(str2);
    if(len1==len2){
        sort(str1, str1+len1);
        sort(str2, str2+len2);
        if(strcmp(str1,str2)==0){
            cout<<"anagram";
        }
    }
    else{
        cout<<"not";
    }
}
