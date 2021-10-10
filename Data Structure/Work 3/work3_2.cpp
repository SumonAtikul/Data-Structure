#include<bits/stdc++.h>
using namespace std;

int Anagram(string str1,string str2)
{
    int s1, s2;
    s1 = str1.length();
    s2 = str2.length();

    string x1 = "", x2 = "";

    for(int i = 0; i < s1; i++){
		if(str1[i] != ' '){
		x1 += (tolower(str1[i]));
	}
	}
    for(int i = 0; i < s2; i++){
		if(str2[i] != ' '){
		x2 += (tolower(str2[i]));
	}
	}

	sort (x1.begin(),x1.end());
    sort (x2.begin(),x2.end());

	if(x1 != x2){
		return false;
	}
	else{
		return true;
	}

}
int Anagram(string str1, string str2);

int main()
{
    string str1,str2;
    cout << "Enter 1st string: ";
    getline(cin,str1);
    cout << "Enter 2nd string: ";
    getline(cin,str2);

    if(Anagram(str1,str2)){
        cout << str1 << " " << "is an Anagram of" << " " << str2 << endl;
    }
    else{
        cout << str1 << " " << "is not an Anagram of" << " " << str2 << endl;
    }

}
