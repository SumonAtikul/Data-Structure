#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long int tc, t, count=0;
    cin >> tc >> t;
    unsigned long int temp1, temp2;
    for(int i=0; i<tc; i++)
    {
        unsigned long int a, b;
        cin >> a >> b;
        temp1=a*a+b*b;
        double temp2=sqrt(temp1);
        if(temp2<=t){
            count++;
        }

    }
    cout << count << endl;


}
