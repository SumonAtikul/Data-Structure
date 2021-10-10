#include<bits/stdc++.h>
using namespace std;
void sort_elements(int a[], int num_elements);
int main()
{
    int a[100], i, num_elements;
    cout << "Enter Number of Elements: ";
    cin >> num_elements;
    for(i = 0; i <num_elements; i++){
        cin >> a[i];
    }
    sort_elements(a, num_elements);
    return 0;
}
void sort_elements(int a[], int num_elements){
    int i, j, temp;
    for(i = 0; i <num_elements-1; i++){
        int flag = 0;
        for(j = 0; j<num_elements-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag++;
            }
        }
        if(flag == 0){
            break;
        }
    }
    for(i = 0; i<num_elements; i++){
        cout << a[i] << "  ";
    }
}

