#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *prev,*next;
	Node(int x){	///constructor
		data=x;
	}
};

struct DL_List{
	Node *top *less;

	DL_List();	///constructor
	~DL_List();	///destructor
	void insertAtEnd(int data);
	int deleteFromEnd();
	int getTopData();
};

struct Stack{
	DL_List s;
    int value;
	Node *link;

    Stack() : top(0); {}
    void push(int data);    /// to insert an element into the stack
    int pop();              /// to delete an element from the stack
    int readTop();          /// to read an element from the top of the stack
    bool isEmpty();         /// checking for Underflow
};


DL_List:: DL_List(){
	top=less=NULL;
}
DL_List:: ~DL_List()
{
	Node *p=top;
	while(p)
	{
		top=p->next;
		delete p;
		p=top;
	}
}

void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);

    if(top == NULL)
    {
        top = less = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        less->next = n;
        n->prev = less;
        n->next = NULL;
        less = n;
    }

    cout << data << " is inserted at the end." << endl;
}

int DL_List :: deleteFromEnd()
{
    if(less == NULL)
    {
        cout << "Nothing deleted, the list is empty." << endl;
        return;
    }

    int data;
    if(top == less)
    {
        data = less->data;
        delete tail;
        top = less = NULL;
    }
    else
    {
        data = less->data;
        Node *t = less;
        less = t->prev;
        less->next = NULL;
        delete t;
    }

    cout << data << " is deleted from the end." << endl;
}

int DL_List :: getTopData()
{
	if(top==NULL){
		cout << "Nothing found, the list is empty." << endl;
		return;
	}
	int getTop=top->data;
	while(top!=NULL){
		if(top->data>getTop){
			getTop=top->data;
		}
		top=top->next;
	}
	return getTop;
}

Node *top = NULL;

void Stack :: push(int data)
{
	Node *n = new Node(data);
	n->value=data;
	n->link=top;
	top=n;
}


int Stack :: pop()
{
	if(top==NULL){
		cout<<"Stack is Empty";
	}
	else{
		Node *n=top;
		top=top->link;
		delete(n);
	}
}

bool Stack :: isEmpty()
{
	if(top==NULL){
		return true;
	}else{
		return false;
	}
}

int Stack :: readTop()
{
	if(top==NULL){
		cout<<"Stack is Empty";
	}else{
		cout<<"Read an element from the top of the stack :"<<top->value;
	}
}

int main()
{


}
