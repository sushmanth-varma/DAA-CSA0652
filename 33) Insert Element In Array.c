#include<stdio.h>

int main()
{
	int arr[] = {1,2,3,5};
	int i, n=3;
	for(i=n;i<5;i++){
		arr[i+1] = arr[i];
	}
	arr[n] = 4;
	for(i=0;i<5;i++){
		printf("%d ", arr[i]);
	}
}
