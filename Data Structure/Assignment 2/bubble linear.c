#include<stdio.h>
int linear_search(int *a, int n, int item);
int bubble_sort(int *a, int n, int item);
int main()
{
    int a[8]={-11,-2,4,12,18,25,37,79};
    int value, item;
    printf("Enter a value: ");
    scanf("%d", value);
    return 0;
    int location = linear_search(a,8,value);
    if(location == -1){
        printf("not found\n");
    }
    else{
        printf("found");
    }
    return 0;
}
int linear_search(int *a, int n, int item);
{
    for(int i=0; i<n; i++){
            bubble_sort=(a, item);
        if(a[i]==item)return i;
    }
    return -1;
}

