#include<iostream>
using namespace std;
int isSorted(int arr[],int n,int& i){
	if(n<i){
		return 1;
	}
	if(arr[i+1]<arr[i]){
		return 0;
	}
	return isSorted(arr,n,++i);
}
int main(){
	int arr[]={1,2,3,4,4,3,2};
	int n=7;
	int i=0;
	if(isSorted(arr,n,i)){
		cout<<"Array is  Sorted\n";
	}
	else{
		cout<<"Array is not Sorted\n";
	}
	return 0;
}
