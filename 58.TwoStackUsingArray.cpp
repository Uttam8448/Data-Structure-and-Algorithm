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
			cout<<"Element "<<data<<"Inserted at stack1 \n";
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
//	
//OUTPUT::
//Top1:0
//Top2:10
//Element 40 Inserted at stack1        
//Top1:1
//Top2:10
//Element 30 Inserted at stack1        
//Top1:2
//Top2:10
//Element 20 Inserted at stack1        
//Top1:3
//Top2:10
//Element 10 Inserted at stack1        
//Top1:3
//Top2:9
//Element 100 Inserted at stack2       
//Top1:3
//Top2:8
//Element 90 Inserted at stack2        
//Top1:3
//Top2:7
//Element 80 Inserted at stack2        
//Poping 80 from stack 2
//Top1:3
//Top2:8
//Poping 10 from stack 1
//Top1:2
//Top2:8
//Top1:3
//Top2:8
//Element 10 Inserted at stack1        
//Top1:3
//Top2:7
//Element 80 Inserted at stack2        
//Top1:3
//Top2:6
//Element 70 Inserted at stack2        
//Top1:3
//Top2:5
//Element 60 Inserted at stack2        
//Top1:3
//Top2:4
//Element 50 Inserted at stack2        
//printing the stack:
//Poping 10 from stack 1
//Top1:2
//Top2:4
//Poping 20 from stack 1
//Top1:1
//Top2:4
//Poping 30 from stack 1
//Top1:0
//Top2:4
//Poping 40 from stack 1
//Top1:-1
//Top2:4
//Poping 50 from stack 2
//Top1:-1
//Top2:5
//Poping 60 from stack 2
//Top1:-1
//Top2:6
//Poping 70 from stack 2
//Top1:-1
//Top2:7
//Poping 80 from stack 2
//Top1:-1
//Top2:8
//Poping 90 from stack 2
//Top1:-1
//Top2:9
//Poping 100 from stack 2
//Top1:-1
//Top2:10

