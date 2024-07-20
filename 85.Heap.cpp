#include<iostream>
using namespace std;

class Heap{
	public:
		int arr[101];
		int size;
		
		Heap(){
			size = 0;
		}
		void insert(int value) {
			size = size +1;
			int index = size;
			arr[index]=value;
			
		//Placing its value at right(correct) position
//  		while(index > 1 && (arr[index]>arr[index/2]){
//				int temp=arr[index];
//				arr[index]= arr[index/2];
//				arr[index/2] = temp;
//				index=index/2;
//			}
		//Placing its value at right(correct) position
		// 1 based Heap
		while(index>1){
			int parentIndex = index/2;
			if(arr[index] > arr[parentIndex]){
				swap(arr[index] , arr[parentIndex]);
				index = parentIndex;
			}
			else{
				break;
			}
		}
		}
		void print(){
			cout<<"\nprinting the Heap : "<<endl;
			for(int i=1;i<=size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		int deleteinHeap(){
			//replace root node value with last node data
			int ans=arr[1];
			arr[1] = arr[size];
			size--;
			//place root node ka data on its correct position
			int index=1;	//root node
			while(index<size){
				int leftChildIndex=2*index;
				int rightChildIndex=2*index+1;
				int largest = index;
				if(leftChildIndex < size && arr[largest] < arr[leftChildIndex]){
					largest = leftChildIndex;
				}
				if(rightChildIndex < size && arr[largest] < arr[rightChildIndex]){
					largest = rightChildIndex;
				}
				if(largest == index) {
					//value is at correct position 
					return ans;
				}
				else{
					swap(arr[index],arr[largest]);
					index=largest;
				}
			}
			return ans;
		}
		void Heapify(int array[],int n,int i){
			 int index = i;
			 int leftChildIndex = 2 * i;
			 int rightChildIndex = 2 * i + 1;
			 int largest = index;
			 
			 if(leftChildIndex < n && array[largest] < arr[leftChildIndex]){
			 	largest = leftChildIndex;
			 }
			 if(rightChildIndex < n && array[largest] < arr[rightChildIndex]){
			 	largest = rightChildIndex;
			 }
			 if(largest!=index){
			 	swap(array[largest],array[index]);
			 	index=largest;
			 	Heapify(arr,n,index);
			 }
		}
};
int main(){
//	Heap h;
//	h.arr[0]=-1;
//	h.arr[1] = 100;
//	h.arr[2] = 50;
//	h.arr[3] = 60;
//	h.arr[4] = 40;
//	h.arr[5] = 45;	
//	h.size = 5;
//	
//	h.print();
//	h.insert(110);
//	cout<<"Inserted 110";
//	h.print();
//	cout<<h.deleteinHeap()<<" is deleted";
//	h.print();
	Heap h;
	h.arr[0]=-1;
	h.arr[1] = 11;
	h.arr[2] = 9;
	h.arr[3] = 6;
	h.arr[4] = 3;
	h.arr[5] = 4;	
	h.size = 5;
	
	h.print();
	h.deleteinHeap();
	h.insert(2);
	cout<<"Inserted 2";
	h.print();
//	cout<<h.deleteinHeap()<<" is deleted";
	h.deleteinHeap();
	h.insert(8);
	cout<<"Inserted 8";
	h.print();
//	h.print();
	return 0;
}
//printing the Heap :
//100 50 60 40 45
//printing the Heap :
//110 50 100 40 45 60
//110 is deleted
//printing the Heap :
//100 50 60 40 45
