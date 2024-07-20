#include<iostream>
using namespace std;
class CirQueue{
	public:
		int size;
		int *arr;
		int front;
		int rear;
		
		CirQueue(int size){
			this->size=size;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
		void push(int ele){
			//Queue full
			//single element case -> first element
			//circular nature
			//normal flow
			if(front==0 && rear==size-1){
				cout<<"Q is full, cannot insert \n"<<endl;
				return;
			}
			else if(rear==front-1){
				cout<<"Q is full, cannot insert \n"<<endl;
				return;
			}
			else if(front==-1){
				front=rear=0;
				arr[rear]=ele;
			}
			else if(rear==size-1 && front!=0){
				rear=0;
				arr[rear]=ele;
			}
			else{
				rear++;
				arr[rear]=ele;
			}
		}
		void pop(){
			//empty check
			//single element
			//circular nature
			//normal flow
			if(front==-1){
				cout<<"Q is empty ,cannot pop!!\n";
			}
			else if(front==rear){
				arr[front]=-1;
				front=rear=-1;
			}
			else if(front==size-1){
				front = 0;
			}
			else{
				arr[front]=-1;
				front++;
			}
		}
		int frontEle(){
			return arr[front];
		}
};
int main(){
	CirQueue cq(10);
	cq.push(10);
	cq.push(20);
	cq.push(30);
	cq.push(40);
	cq.push(50);
	cq.push(60);
	cq.push(70);
	cq.push(80);
	cq.push(90);
	cq.push(100);
	cq.push(110);
	cq.pop();
	cq.pop();
	cq.push(56);
	cq.push(34);
	for(int i=0;i<10;i++){
		cout<<cq.frontEle()<<endl;
		cq.pop();
		
	}
	return 0;
}
