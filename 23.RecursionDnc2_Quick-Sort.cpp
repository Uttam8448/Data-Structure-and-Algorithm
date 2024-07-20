#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
	//choose pivot
	int pivotIndex=s;
	int pivotElement=arr[s];
	int count=0;
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivotElement){
			count++;
		}
	}
	int rightIndex=s+count;
	swap(arr[pivotIndex],arr[rightIndex]);
	pivotIndex=rightIndex;
	//Step3: left me chote and right  me bade
	int i=s;
	int j=e;
	while(i<pivotIndex && j>pivotIndex){
		while(arr[i]<=
		pivotElement){
			i++;
		}
		while(arr[j]>pivotElement){
			j--;
		}
		if(i<pivotIndex && j>pivotIndex){
			swap(arr[i],arr[j]);	
		}
	}
	return pivotIndex;
}
void QuickSort(int arr[],int s,int e){
	if(s>=e){
		return;
	}
	//partition logic
	int p=partition(arr,s,e);
	
	//recursive call
	QuickSort(arr,s,p-1);
	QuickSort(arr,p+1,e);

}
int main(){
	int arr[]={8,1,3,4,20,50,30};
	int n = 7;
	int s=0;
	int e=n-1;
	QuickSort(arr,s,e);
	for(int i=0;i<7;i++){
		cout<<arr[i]<<"\n";
	}
	return 0;  
}
