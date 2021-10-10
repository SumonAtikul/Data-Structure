#include<bits/stdc++.h>
using namespace std;

bool IsOperand(string t);
bool IsOperator(string t);
int precedence(string OP);
bool checkHighOrEql(string OP_1, string OP_2);
///int evaluatePostfix();

struct Stack
{
    string putChar[100];
    int top;
    Stack() : top(0) {}
    void push(string t);
    string pop();
    string readTop();
    bool isEmpty();
};

void Stack :: push(string value)
{
    putChar[top] = value;
    top++;
}

string Stack :: pop()
{
    if( isEmpty() )
    {
        cout << "Stack is empty." << endl;
        return "0";
    }
    top--;
    return putChar[top];
}

bool Stack :: isEmpty()
{
    if(top == 0) return true;
    else return false;
}

string Stack :: readTop()
{
    return putChar[top-1];
}


int main()
{
    Stack s;
    string infix, postfix[100];

    cout << "\t\tInfix to Postfix Converter v1.0\n";
    cout << "\t\t===============================\n\n";

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    infix += " )";
    s.push("(");

    istringstream token(infix);
    string t, p;
    int i=0, j;

    while(token>>t)
    {
        if(t == "(")
        {
            s.push(t);
        }
        else if(IsOperand(t))
        {
            postfix[i] += t;
            i++;
        }
        else if(IsOperator(t))
        {
            while(!s.isEmpty() && checkHighOrEql(s.readTop(), t))
            {
                postfix[i] += s.readTop();
                i++;
                s.pop();
            }
            s.push(t);
        }
        else if(t == ")")
        {
            while(!s.isEmpty() && s.readTop() != "(")
            {
                postfix[i] += s.readTop();
                i++;
                s.pop();
            }
            s.pop();
        }
    }

    cout << endl << "The equivalent postfix expression is: ";
    for(j=0; j<i; j++) cout << postfix[j] << " ";
    cout << endl << endl;

    /// Evaluation function is given below. I just wrote the function. As there are data type problems that's why I kept that as comments.
    //evaluatePostfix();

    return 0;
}

bool IsOperand(string t)
{
    if(t >= "A" && t <= "Z") return true;
    if(t >= "a" && t <= "z") return true;
    if(t >= "0" && t <= "9") return true;
    return false;
}

bool IsOperator(string t)
{
    if(t == "+" || t == "-" || t == "*" || t == "/" || t == "^")
    {
        return true;
    }
    return false;
}

int precedence(string OP)
{
    if(OP == "+" || OP == "-") return 1;
    if(OP == "*" || OP == "/") return 2;
    if(OP == "^") return 3;

    return 0;
}


bool checkHighOrEql(string OP_1, string OP_2)
{
    int p_1 = precedence(OP_1);
    int p_2 = precedence(OP_2);
    if(p_1 == p_2)
    {
        if(OP_1 == "^")
        {
            return false;
        }
        return true;
    }
    return (p_1 > p_2 ? true : false);
}

/*int evaluatePostfix()
{
    Stack es;
    string st;
    getline(cin, st);
    istringstream token(st);
    string t;
    while(token >> t)
    {
        if(t == "(" || t == ")")
        {
            continue;
        }
        if(IsOperand(t))
        {
            es.push(t);
        }
        if(IsOperator(t))
        {
            int A = es.pop();
            int B = es.pop();
            int res;
            if(t == "+")
            {
                res = B + A;
                es.push(res);
            }
            if(t == "-")
            {
                res = B - A;
                es.push(res);
            }
            if(t == "*")
            {
                res = B * A;
                es.push(res);
            }
            if(t == "/")
            {
                res = (B / A);
                es.push(res);
            }
            if(t == "^")
            {
                res = pow(B, A);
                es.push(res);
            }
        }
    }
    cout << es.readTop() << endl;
}
*/
