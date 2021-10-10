#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
    Node(int x)   /// constructor
    {
        data = x;
    }
};
struct DL_List
{
    Node *top, *tail;
    DL_List();  /// constructor
    ~DL_List(); /// destructor
    void insertAtEnd(int data);
    int deleteFromEnd();
    int displyTopData();
};

struct Stack
{
    DL_List s;
    int value;
    Node *prev,*top;
    Stack() {}
    void push(int data);
    void pop();
    int readTop();
    bool isEmpty();
};

DL_List :: DL_List()
{
    top = tail = NULL;
}

DL_List :: ~DL_List()
{
    Node *p = top;
    while(p)
    {
        top = p->next;
        delete p;
        p = top;
    }
}

void Stack :: pop()
{
    if(top==NULL) cout << "The stack is empty." << endl;
    Node *t=top;
    int value=top->data;
    top=top->prev;
    delete t;
    cout << value << " is popped to the stack." << endl;
}

void Stack :: push(int data)
{
    Node *t=new Node (data);
    t->data=data;
    t->prev=top;
    top=t;
    cout << data << " is pushed to the stack." << endl;
}

int Stack :: readTop()
{
    if(top==NULL) return -1;
    else return top->data;
}

bool Stack :: isEmpty()
{
    if(top==NULL) return true;
    else return false;
}

int DL_List::displyTopData()
{
    int value;
    if(top!=tail)
    {
        value = tail->data;
    }
    return value;
}

void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);
    if(top == NULL)
    {
        top = tail = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        n->next = NULL;
        tail = n;
    }
    cout << data << " is inserted at the end." << endl;
}

int DL_List :: deleteFromEnd()
{
    if(tail == NULL)
    {
        cout << "Nothing deleted, the list is empty." << endl;
        return -1;
    }

    int data;
    if(top == tail)
    {
        data = tail->data;
        delete tail;
        top = tail = NULL;
    }

    else
    {
        data = tail->data;
        Node *t = tail;
        tail = t->prev;
        tail->next = NULL;
        delete t;
    }
    return data;
}

int main()
{
    DL_List myList;
    srand(time (0));

    for(int i=0; i<5; i++)
    {
        myList.insertAtEnd(rand() %30);
    }

    cout <<myList.deleteFromEnd() << " is delete from end." << endl;
    cout <<myList.displyTopData() << " is the top item of the stack." << endl;
    cout << "----By using Stack----" << endl;

    Stack myStack;
    srand(time(0));
    for(int i=0; i<5; i++)
    {
        myStack.push(rand()%30);
    }

    cout << myStack.readTop() << " is the top item of the stack." << endl;
    myStack.pop();
    return 0;
}
