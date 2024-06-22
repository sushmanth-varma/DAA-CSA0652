#include<stdio.h>

int main()
{
	int arr[] = {1,2,3,4,5};
	int mid,coun,target=3,start=0,end=sizeof(arr)/sizeof(arr[0])-1;
	while(start<=end){
		mid = (start+end)/2;
		if(arr[mid]==target){
			coun = 1;
			break;
		}
		else if(arr[mid]<target){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	if(coun==1){
		printf("Element Present");
	}
	else{
		printf("Element Not Present");
	}
}
