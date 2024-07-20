#include<iostream>
using namespace std;
class Stack{
	public:
		int *arr;		//pointer to stack in heap
		int size;
		int top;
		
		Stack(int size){
			this->size=size;
			arr = new int[size];
			top=-1;
		}
		void push(int data){
			if(size-top==1){				//Stack overflow
				cout<<"Stack is full!!\n";
				return;
			}
			this->top++;
			arr[top]=data;
		}
		void pop(){
			if((this->top)==-1){				//Stack underflow
				cout<<"Stack is empty!!";
				return;
			}
			(this->top)--;
		}
		int getTop(){
			if((this->top)==-1){				//Stack underflow
				cout<<"Stack is empty!!";
				return -1;
			}
			return arr[top];
		}
		int getSize() {
			return top;
		}
		bool  isEmpty() {
			if(top==-1){
				return true;
			}
			return false;
		}
};

int main(){
	Stack st(7);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	st.push(70);
	st.pop();
	st.push(80);
	cout<<st.getTop()<<endl;
	cout<<st.isEmpty();
	
	return 0;
}
