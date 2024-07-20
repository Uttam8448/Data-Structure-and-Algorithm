#include<iostream>
using namespace std;
class Deque{
	public:
		int rear,front,size;
		int* arr;
		Deque(int size){
			this->size=size;
			rear,front=-1;
			arr=new int[size];
		}
		void push_rear(int ele){
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
				
			}
			else if(rear==size-1 && front!=0){
				rear=0;
			}
			else{
				rear++;
			}
			arr[rear]=ele;
		}
		void push_front(int data){
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
				
			}
			else if(rear!=size-1 && front==0){
				front=size-1;
			}
			else{
				front--;
			}
			arr[front]=data;
		}
		void pop_front(){
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
				front++;
			}
		}
		void pop_rear(){
			if(rear==-1){
				cout<<"Q is empty,cannot pop!1\n";
			}
			else if(front==rear){
				front=rear=-1;
			}
			else if(rear==0){
				rear=size-1;
			}
			else{
				rear--;
			}
		}
		void print(){
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
		}
};

int main(){
	Deque d(10);
	d.push_front(10);
	d.push_rear(20);
	d.push_front(30);
	d.push_rear(40);
	//d.print();
	d.pop_front();
	d.pop_front();
	d.pop_rear(); 
	d.push_front(30);
	d.push_front(50);
	d.push_front(60);
	d.push_front(70);
	d.push_front(80);
	d.push_front(90);
	d.push_front(100);
	d.push_front(110);
	d.push_rear(20);
	d.print();
	
}
