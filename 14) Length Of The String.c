#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter your name : ");
	gets(str);
	printf("Size of your name : %d", strlen(str));
}
