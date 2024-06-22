#include<stdio.h>

int main()
{
	int limit = 20;
	int i,j, coun=0;
	for(i=2;i<=limit;i++){
		coun = 0;
		for(j=2;j<i;j++){
			if(i%j==0){
				coun = 1;
				break;
			}
		}
		if(coun==0){
			printf("%d ",i);
		}
	}
}
