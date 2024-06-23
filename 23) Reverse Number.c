#include<stdio.h>

int main()
{
	int num = 1234;
	int dup = 0;
	while(num){
		int digit = num%10;
		dup = dup*10+digit;
		num = num/10;
	}
	printf("%d", dup);
}
