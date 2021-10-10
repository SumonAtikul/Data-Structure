#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)
    {
        data = x;
    }
};

struct DL_List {
    Node *top;
    DL_List();  /// constructor
    ~DL_List(); /// destructor
    void insertAtEnd(int data);
    int deleteFromEnd();
    int getTopData();
};

DL_List :: DL_List() {
    top = NULL;
}
DL_List :: ~DL_List() {
    Node *t;
    while(top!=NULL)
    {
        t = top->next;
        delete top;
        top = t;
    }
}

void DL_List::insertAtEnd(int data) {
    Node *p = new Node(data);
    if(top==NULL)
    {
        top=p;
        top->next=NULL;
        top->prev=NULL;
    }
    else
    {
        p->prev=top;
        top->next=p;
        top=p;
    }
    cout<<getTopData()<<" has been pushed to the stack.\n";
}

int DL_List::deleteFromEnd()
{
    if(top == NULL)
    {
        return -1;
    }
    top=top->prev;
    return 1;
}

int DL_List::getTopData()
{
    if(top == NULL)
    {
        return -1;
    }
    return top->data;
}

struct Stack
{
    DL_List S;
    Stack() {}
    void push(int data);
    int pop();
    int readTop();
    bool isEmpty();
};

void Stack :: push(int data)
{
    S.insertAtEnd(data);
}

int Stack :: pop()
{
    if(!S.deleteFromEnd())
        puts("Nothing to pop. Stack is Empty.");
    return 0;
}

int Stack :: readTop()
{
    if(isEmpty())
        return -1;
    return S.getTopData();
}

bool Stack :: isEmpty()
{
    if(S.getTopData()==-1)
        return true;
    else
        return false;
}

/*int main()
{
    Stack Stack;
    srand(time(0));
    for(int i=0; i<5; i++)
    {
        Stack.push(rand()%30);
    }

    cout << Stack.readTop() << " is the top item of the stack." << endl;
    Stack.pop();
    return 0;
}*/
int main()
{
    Stack Stack;

    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.push(40);
    Stack.push(50);
    cout << Stack.pop() << " is popped from the stack." << endl;
    cout << Stack.pop() << " is popped from the stack." << endl;
    cout << "Top of stack: " << Stack.readTop() << endl;
    return 0;

}



