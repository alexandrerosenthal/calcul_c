#include <stdio.h>
#include <stdlib.h>

int fact_it (int n){
	int i;
	int k;
	k=n;
	for (i = n-1 ; i > 0 ; i--){
		k=k*i;
	} 
	return k;
}

int fact_rec (int n){
	if(n == 0){
		return 1;
	} else {
		return n*fact_rec(n-1);
	}
}
int main()
{
	int k;
	k=8;
	k=fact_it(k);
	printf("%d\n", k);
	k=10;
	k=fact_rec(k);
	printf("%d\n", k);
	return 0;
}

