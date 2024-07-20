#include<iostream>
using namespace std;
class Stack{
	public:
		int* arr;
		int size;
		int top1;
		int top2;
	Stack(int size){
		this->size=size;
		arr=new int[size];
		top1=-1;
		top2=size;
	}
	void push1(int data){
		if(top2-top1==1){
			cout<<"Stack Overflow!!\n";
		}
		else{
			top1++;
			cout<<"Top1:"<<top1<<endl;
			cout<<"Top2:"<<top2<<endl;
			cout<<"Element "<<data<<" Inserted at stack1 \n";
			arr[top1]=data;
		}
	}
	void push2(int data) {
		if(top2-top1==1){
			cout<<"Stack Overflow!!\n";
		}
		else{
			top2--;
			cout<<"Top1:"<<top1<<endl;
			cout<<"Top2:"<<top2<<endl;
			cout<<"Element "<<data<<" Inserted at stack2 \n";
			arr[top2]=data;
			
		}
	}
	void pop1(){
		if(top1==-1){
			cout<<"Stack1 is empty!!";
		}
		else{
			cout<<arr[top1]<<"\n";
			top1--;
			cout<<"Top1:"<<top1<<endl;
			cout<<"Top2:"<<top2<<endl;
		}
	}
	void pop2(){
		if(top2==size){
			cout<<"Stack2 is empty!!";
		}
		else{
			cout<<arr[top2]<<"\n";
			top2++;
			cout<<"Top1:"<<top1<<endl;
			cout<<"Top2:"<<top2<<endl;
		}
	}
	
};
int main(){
	Stack s1(10);
	s1.push1(40);
	s1.push1(30);
	s1.push1(20);
	s1.push1(10);
	s1.push2(100);
	s1.push2(90);
	s1.push2(80);
	s1.pop2();
	s1.pop1();
	s1.push1(10);
	s1.push2(80);
	s1.push2(70);
	s1.push2(60);
	s1.push2(50);
	cout<<"printing the stack: \n";
	while(s1.top1!=-1){
		s1.pop1();
	}
	while(s1.top2!=s1.size){
		s1.pop2();
	}
	return 0;
	}
