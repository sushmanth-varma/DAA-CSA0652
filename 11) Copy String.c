#include<stdio.h>

int main()
{
	char str[] = "SUSHMANTH";
	int length = sizeof(str)/sizeof(str[0]);
	char dest[length];
	int i;
	for(i=0;i<length;i++){
		dest[i] = str[
		i];
	}
	printf("%s", dest);
}








