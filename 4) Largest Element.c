#include<stdio.h>

int main()
{
	int arr[] = {4,2,5,2,1,9};
	int leng = sizeof(arr)/sizeof(arr[0]);
	int max = arr[0];
	int i = 0;
	for(i=0;i<leng;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	printf("Largest element : %d", max);
}
