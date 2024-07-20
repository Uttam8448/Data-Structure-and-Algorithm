#include<iostream>
#include<stack>
using namespace std;

void SortStackHelper(stack<int> &st,int target){
	if(st.empty() || st.top()>target){
		st.push(target);
		return;
	}
	int temp=st.top();
	st.pop();
	SortStackHelper(st,target);
	st.push(temp);
}



void SortStack(stack<int> &st){
	if(st.empty()){
		return;
	}
	int target=st.top();
	st.pop();
	SortStack(st);
	SortStackHelper(st,target);
	
}
void print(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}

int main(){
	stack<int> st;
	st.push(7);
	st.push(11);
	st.push(3);
	st.push(5);
	st.push(9);
	SortStack(st);
	print(st);
}
