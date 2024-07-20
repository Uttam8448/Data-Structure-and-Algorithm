#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> st;
	
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	
	//remove
	st.pop();
	//check element on top
	cout<< "Element on top is: "<<st.top() <<endl;
	cout<<"Size of stack is: "<<st.size()<<endl;
	if(st.empty())
		cout<<"Stack is Empty!!!"<<endl;
	else
		cout<<"Stack is not empty"<<endl;
	stack<int> s;
	s.push(10);
	
	return 0;
}
