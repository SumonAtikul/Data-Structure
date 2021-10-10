#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;

struct Heap{
    int h[MAX];
    int heapSize;

    Heap();
    void insertData(int data);
    int deleteRoot();
    void heapifyUp(int i);
    void heapifyDown(int i);
    void display();
};


Heap :: Heap()
{
    heapSize = 0;
}


void Heap :: insertData(int data)
{
    h[++heapSize] = data;
    heapifyUp(heapSize);
}


int Heap :: deleteRoot()
{
    int root = h[1];

    h[1] = h[heapSize--];
    heapifyDown(1);

    return root;
}


void Heap :: heapifyUp(int i)
{
    int p = i / 2; /// index of parent node
    if(p < 1)
        return;

    if(h[i] > h[p])
    {
        swap(h[i], h[p]);
        heapifyUp(p);
    }
}


void Heap :: heapifyDown(int i)
{
    int left = 2 * i;
    int right = left + 1;
    int maxChild;

    if(left > heapSize)
        return;

    if(left == heapSize)
        maxChild = left;
    else
        maxChild = (h[left] > h[right]) ? left : right;

    if(h[i] < h[maxChild])
    {
        swap(h[i], h[maxChild]);
        heapifyDown(maxChild);
    }
}


void Heap :: display()
{
    cout << "The elements are:";
    for(int i=1; i<=heapSize; i++)
        cout << " " << h[i];
    cout << endl << endl;
}


int main()
{
    Heap hp;
    int choice, data;

    while(1)
    {
        cout << "\tHeap Operations" << endl;
        cout << "\t---------------" << endl << endl;
        cout << "1. Insert An Item." << endl;
        cout << "2. Delete Root." << endl;
        cout << "3. Print the elements." << endl;
        cout << "4. Exit." << endl << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter an item: ";
            cin >> data;
            hp.insertData(data);
            break;
        case 2:
            if(hp.heapSize == 0)
                cout << "The heap is empty. Nothing deleted." << endl;
            else
                cout << hp.deleteRoot() << " is deleted from heap" << endl;
            break;
        case 3:
            break;
        case 4:
            return 0;
        }
        hp.display();
        cin.get();
        cout << "Press any key to continue ...";
        cin.get();
        printf("\033c"); 	// for linux only
        //system("clear"); 	// OS specific. In windows, it is system("cls");
    }
}
