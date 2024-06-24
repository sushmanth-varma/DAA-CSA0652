#include<stdio.h>

int main()
{
	int arr[] = {4,2,45,1,3,9};
	int i;
	int min = arr[0];
	int max = arr[0];
	for(i =0 ;i<(sizeof(arr)/sizeof(arr[0]));i++){
		if(arr[i]>max){
			max = arr[i];
		}
		else if(arr[i]<min){
			min = arr[i];
		}
	}
	printf("%d %d", min, max);
}
