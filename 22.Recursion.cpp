#include<iostream>
using namespace std;

void merge(int* arr,int s,int e){
	int mid=s+ (e-s)/2;
	
	int len1 = mid-s+1;
	int len2 = e-mid;
	
	int* left = new int[len1];
	int* right = new int[len2];
	//copy kardo values
	int k=s;		//0nahi hai kyuki s kuch bhi aa sakta hai
	for(int i=0;i<len1;i++){
		left[i]=arr[k];
		k++;
	}
	k=mid+1;
	for(int i=0;i<len2;i++){
		right[i]=arr[k];
	}
	
	//merge logic
	
	int leftIndex=0;
	int rightIndex=0;
	int mainArrayIndex=s;
	while(leftIndex<len1 && rightIndex<len2){
		if(left[leftIndex]<right[rightIndex]){
			arr[mainArrayIndex++]=left[leftIndex++];
		}
		else{
			arr[mainArrayIndex++]=right[rightIndex++];
		}
	}
	//copy logic for remaining element in left or right array
	while(leftIndex<len1){
		arr[mainArrayIndex++]=left[leftIndex++];
	}
	while(rightIndex<len2){
		arr[mainArrayIndex++]=right[rightIndex++];
	}
	//Todo:Delete left and right wala array
	
}

void mergeSort(int* arr, int a,int e){
	if(s>=e){
		return;
	}
	int mid=s+(e-s)/2;
	mergeSort(arr,s,mid);	//left part
	mergeSort(arr,mid+1,e);	//right part
	//now merge 2 sorted arrays
	merge(arr,s,e);
}
int main()
{
	int arr[]={4,5,13,2,12};
	int n=5;
	int s=0;
	int e=4;
	mergeSort(arr,s,e);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
