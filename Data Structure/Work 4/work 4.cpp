#include <bits/stdc++.h>
using namespace std;

struct BigInt
{
    string s;
    int sign;

    int size();
    BigInt inverseSign();
    BigInt normalize(int newSign);

    friend istream& operator>>(istream& is, BigInt &x);
    friend ostream& operator<<(ostream& os, BigInt &x);

    BigInt operator + (BigInt b);
    BigInt operator - (BigInt b);
    bool operator < (const BigInt&) const;
    bool operator > (const BigInt&) const;
    bool operator == (const BigInt&) const;

};

int BigInt::size()
{
    return (int)s.size();
}

BigInt BigInt::inverseSign()
{
    sign *= -1;
    return (*this);
}

BigInt BigInt::normalize(int newSign)
{
    for(int i=size()-1; i>0 && s[i]==0; i--)
        s.erase(s.begin()+i);
    sign = (size()==1 && s[0]=='0') ? 1 : newSign;
    return (*this);
}

istream& operator >> (istream& is, BigInt &x)
{
    string t;
    is >> t;
    x.s = (t[0] == '-') ? t.substr(1) : t;
    reverse(x.s.begin(), x.s.end());
    x.normalize(t[0]=='-'? -1 : 1);
    return is;
}

ostream& operator << (ostream& os, BigInt &x)
{
    string t = x.s;
    reverse(t.begin(), t.end());
    if(x.sign == -1) os << '-';
    os << t;
    return os;
}

BigInt BigInt::operator + (BigInt b)
{
    BigInt c;

    for(int i=0, carry=0; i<size() || i<b.size() || carry; i++)
    {
        carry += (i<size() ? s[i]-48 : 0) + (i<b.size()? b.s[i]-48 : 0);
        c.s += (carry % 10 + 48);
        carry /= 10;
    }

    return c.normalize(sign);
}

BigInt BigInt :: operator - (BigInt b)
{
    BigInt c;

    for(int i=0, borrow=0, k; i<size(); i++)
    {
        k = s[i]-48 - borrow - (i<b.size() ? b.s[i]-48 : 0);
        c.s += (k >= 0) ? (k+48) : (k+58);
        borrow = (k >= 0) ? 0 : 1;
    }

    return c.normalize(sign);
}

bool BigInt::operator < (const BigInt& b) const
{
    if(sign != b.sign) return sign < b.sign;
    if(s.size() != b.s.size())
        return (sign==1) ? s.size()<b.s.size() : s.size()>b.s.size();
    for(int i=s.size()-1; i>=0; i--) if(s[i] != b.s[i])
            return (sign==1) ? s[i]<b.s[i] : s[i]>b.s[i];
    return false;
}

bool BigInt::operator > (const BigInt& b) const
{
    if(sign != b.sign) return sign > b.sign;
    if(s.size() != b.s.size())
        return (sign==1) ? s.size() > b.s.size() : s.size() > b.s.size();
    for(int i=s.size()-1; i>=0; i--) if(s[i] != b.s[i])
            return (sign==1) ? s[i]> b.s[i] : s[i]> b.s[i];
    return false;
}

bool BigInt::operator == (const BigInt& b) const
{
    for(int i=0; i<s.size(); i++) if(s==b.s && sign==b.sign)
        return true;
    return false;
}

int main()
{
    BigInt a, b, c;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    c = a + b;
    cout << "sum: " << c << endl;

    c = a - b;
    cout << "difference: " << c << endl;

    if(a < b)
        cout << "a is less than b." << endl;
    else
        cout << "a is NOT less than b." << endl;

    if(a > b)
        cout << "b is less than a." << endl;
    else
        cout << "b is NOT less than a." << endl;

    if(a == b)
        cout << "a is equal b." << endl;
    else
        cout << "a is NOT equal b." << endl;

    return 0;
}

