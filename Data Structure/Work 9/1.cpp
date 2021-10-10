#include<bits/stdc++.h>
using namespace std;

int ACK(int m, int n)
{
    if (m == 0){
        return n + 1;
    }

    else if((m > 0) && (n == 0)){
        return ACK(m - 1, 1);
    }

    else if((m > 0) && (n > 0)){
        return ACK(m - 1, ACK(m, n - 1));
    }
}

int main()
{
    int A;
    A = ACK(2, 3);
    cout << A << endl;
    return 0;
}
