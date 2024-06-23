#include<stdio.h>

int main()
{
	int num = 1234;
	int i,sum = 0;
	while(num){
		int digit = num%10;
		sum = sum+digit;
		num/=10;
	}
	printf("%d",sum);
}
