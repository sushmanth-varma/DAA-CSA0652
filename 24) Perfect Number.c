#include<stdio.h>

int main()
{
	int sum=0;
	int num = 6;
	int i;
	for(i=1;i<num;i++){
		if(num%i==0){
			sum+=i;
		}
	}
	if(sum==num){
		printf("Its a perfect number");
	}
}
