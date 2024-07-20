#include<iostream>
using namespace std;
void Heapify(int arr[],int n,int i){
	int index = i;
	int leftChildIndex = 2 * i;
	int rightChildIndex = 2 * i + 1;
	int largest = index;
		 
	if(leftChildIndex <= n && arr[largest] < arr[leftChildIndex]){
		largest = leftChildIndex;
	}
	if(rightChildIndex <= n && arr[largest] < arr[rightChildIndex]){
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
void heapSort(int arr[], int n)
    {
        //code here
        if(n==0)	return;
        swap(arr[1],arr[n]);
        n--;
        Heapify(arr,n,1);		//important
        heapSort(arr,n);     
    }
int main(){
//	int arr[]={-1,12,14,13,17,15};
//	BuildHeap(arr,5);
//	cout<<"\nprinting the Heap : "<<endl;
//	for(int i=1;i<=5;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	int arr[]={-1,12,56,43,44,78,87,5,6,3,23,32};
//	BuildHeap(arr,11);
//	cout<<"\nprinting the Heap : "<<endl;
//	for(int i=1;i<=11;i++){
//		cout<<arr[i]<<" ";
//	}
//	heapSort(arr,11);
//	cout<<endl;
//	for(int i=1;i<=11;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
int arr[]={-1,3,11,6,9,4};
	BuildHeap(arr,6);
	cout<<"\nprinting the Heap : "<<endl;
	for(int i=1;i<=6;i++){
		cout<<arr[i]<<" ";
	}
//	heapSort(arr,11);
	cout<<endl;
	for(int i=1;i<=6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
