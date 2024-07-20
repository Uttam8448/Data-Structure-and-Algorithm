#include<iostream>
using namespace std;

void Heapify(int arr[],int n,int i){
	int index = i;
	int leftChildIndex = 2 * i;
	int rightChildIndex = 2 * i + 1;
	int largest = index;
			 
	if(leftChildIndex < n && arr[largest] < arr[leftChildIndex]){
		largest = leftChildIndex;
	}
	if(rightChildIndex < n && arr[largest] < arr[rightChildIndex]){
		largest = rightChildIndex;
	}
	if(largest!=index){
		swap(arr[largest],arr[index]);
		index=largest;
		Heapify(arr,n,index);
		}
}
void BuildHeap(int arr[],int n){
	for(int i = n/2;i>0;i--){
		Heapify(arr,n,i);
	}
}
int main(){
	void BuildHeap(int arr[],int n);
	int arr[]={-1,12,14,13,17,15};
	BuidHeap(arr,5);
	return 0;
}
