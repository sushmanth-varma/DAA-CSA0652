#include<stdio.h>

int fib(n){
	if(n<=1){
		return n;
	}
	return fib(n-1) + fib(n-2);
}
int main()
{
	int n = 5;
	int i;
	for(i=0;i<=n;i++){
		printf("%d ", fib(i));
	}
	return 0;
}
