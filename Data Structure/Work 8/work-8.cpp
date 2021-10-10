#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev, *next;
    Node(int x){
        data = x;
    }
};

struct DL_List{
    Node *head, *tail;

    DL_List(); /// constructor
    ~DL_List(); /// destructor

    void insertAtEnd(int data);
    int deleteFromBeginning();
    void printList();
};

struct Queue{
    DL_List Q;

    Queue() {}
    void enqueue(int data);
    int dequeue();
    void display();
    bool isEmpty();
};

DL_List :: DL_List()
{
    head = tail = NULL;
}

DL_List :: ~DL_List()
{
    Node *p = head;
    while(p)
    {
        head = p->next;
        delete p;
        p = head;
    }
}

void DL_List :: insertAtEnd(int data)
{
    Node *n = new Node(data);

    if(head == NULL)
    {
        head = tail = n;
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

    cout << data << " is enqueued at the end." << endl;
}

int DL_List :: deleteFromBeginning()
{
    if(head == NULL)
    {
        cout << "Nothing dequeued, the list is empty." << endl;
        return -1;
    }

    int data;
    if(head == tail)
    {
        data = head->data;
        delete head;
        head = tail = NULL;
    }
    else
    {
        data = head->data;
        Node *t = head;
        head = t->next;
        head->prev = NULL;
        delete t;
    }

    return data;
}

void DL_List :: printList()
{
    cout << "The list is: ";

    Node *t = head;
    while(t)
    {
        cout << t->data << " <-> ";
        t = t->next;
    }
    cout << "NULL" << endl;
}


void Queue :: enqueue(int data)
{
    Q.insertAtEnd(data);
}

int Queue :: dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
    {
        int dequeued = Q.deleteFromBeginning();
        return dequeued;
    }
}


void Queue :: display()
{
    Q.printList();
}

bool Queue :: isEmpty()
{
    if(Q.head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    myQueue.display();

    cout << myQueue.dequeue() << " dequeued from the queue." << endl;
    cout << myQueue.dequeue() << " dequeued from the queue." << endl;

    myQueue.display();

}
