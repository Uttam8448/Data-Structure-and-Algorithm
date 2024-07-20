#include<iostream>
#include<stack>
using namespace std;
void findmid(stack<int> st,int TotalSize){
	if(st.size()==0){
		cout<<"Empty Stack!!";
		return;
	}
	
	if((TotalSize/2)+1==st.size()){
		cout<<"Middle Element : "<<st.top()<<endl;	
		return;	
	}
	
	int temp = st.top();
	st.pop();
	//recursive call
	findmid(st,TotalSize);
	//Backtrack
	st.push(temp);
}

int main(){
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	findmid(st,st.size());
	return 0;
}

