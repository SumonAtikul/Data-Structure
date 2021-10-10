#include<stdio.h>
int mx=1e7,i,j,n;
int fl[10000005];
int pri[10000005];
void sieve(){
	for (i=2; i*i<mx; i++)
		if (!fl[i])
			for (j=i+i; j<mx; j+=i)
				fl[j]=1;

}
int main(){
	sieve();
	scanf("%d", &n);
    for(int i=2;i<n;i++)
    {
        if(fl[i]==0)
            printf("%d ",i);
    }
	return 0;
}
