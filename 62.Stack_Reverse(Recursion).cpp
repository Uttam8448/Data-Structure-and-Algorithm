#include<iostream>
#include<stack>
using namespace std;
void InsertAtBottom(stack<int> &st,int target){
	if(st.empty()){
		st.push(target);
		return;
	}
	
	int temp = st.top();
	st.pop();
	//recursive call
	InsertAtBottom(st,target);
	//Backtrack
	st.push(temp);
}
void ReverseStack(stack<int> &st){
	//base case
	if(st.empty()){
		return;
	}
	//target nikala
	int target = st.top();
	st.pop();
	//reverse stack
	ReverseStack(st);
	//insert at bottom target ko
	InsertAtBottom(st,target);
}
void print(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main(){
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	cout<<"Before function :\n";
	print(st);
	ReverseStack(st);
	cout<<"\nAfter function :\n";
	print(st);
	return 0;
}
