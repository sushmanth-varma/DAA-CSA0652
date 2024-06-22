	#include<stdio.h>

int main()
{
	char str[] = "SUHSMANTH";
	int len = sizeof(str)/sizeof(str[0]);
	int i;
	for(i=len-1;i>=0;i--){
		printf("%c", str[i]);
	}
}
