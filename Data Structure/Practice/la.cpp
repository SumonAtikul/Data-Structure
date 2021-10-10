#include <stdio.h>
#include <string.h>
int main()
{
    char arr[105];
    int i, len, ans=1;
    gets(arr);

    len = strlen(arr);

    for(i=1;i<len;i++){
        if('A'<=arr[i] && arr[i]<='Z'){
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
