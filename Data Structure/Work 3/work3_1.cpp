#include<bits/stdc++.h>
using namespace std;

int main()
{
    int check = 0;
    string str;
    getline(cin,str);
    	for(int i = 0; i < str[i]; i++){
        if(check == 0){
            str[i] = toupper(str[i]);
            check = 1;
        }
        else if(isspace(str[i])){
            check = 0;
        }
    }
    cout << str << endl;
    return 0;
}
