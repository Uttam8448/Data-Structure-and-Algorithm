#include<iostream>
using namespace std;
class Queue{
	public: 
	int front,rear,size;
	int* arr;
	Queue(int s){
		size=s;
		arr = new int[size];
		front=0;
		rear=0;
	}
	
	void push(int data) {
		if(rear==size){
			cout<<"Queue is Full!!\n"<<endl;
		}
		else{
			arr[rear]=data;
			rear++;
		}
	}
	void pop() {
		if(front==rear){
			cout<<"Queue is empty!!\n";
		}
		else{
			arr[front]=-1;
			front++;
			if(front == rear) {
				front=0;
				rear=0;
			}
		}
	}
	int getFront(){
		if(front == rear){
			cout<<"Queue is Empty!!\n";
			return -1;
		}
		else{
			return arr[front];	
		}
	}
	bool isEmpty(){
		if(front == rear){
			return true;
		}
		else{
			return false;
		}
	}
	int getSize() {
		return rear-front;
	}
};
 int main(){
	Queue q(10);
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(20);
	q.push(20);
	cout<<q.getSize();
	cout<<q.getFront();
	cout<<q.isEmpty();
	return 0;
}
