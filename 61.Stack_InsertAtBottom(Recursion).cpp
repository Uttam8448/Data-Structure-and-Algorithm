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
void print(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<endl;
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
	st.push(60);
	int target=st.top();
	print(st);
	st.pop();
	InsertAtBottom(st,target);
	cout<<"After function :\n";
	print(st);
	return 0;
}

