#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
	stack<int> s;
	
	//Step 1: Put all elements of q into stack
	while(!q.empty()){
		int element=q.front();
		q.pop();
		s.push(element);
		
	}
	
	//Step 2: Put all elements of stack into q
	while(!s.empty()){
		int element=s.top();
		s.pop();
		q.push(element);
	}
	return;
	
}
void print(queue<int> q){
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
}

int main(){
	queue<int> q;
	q.push(3);
	q.push(6);
	q.push(9);
	q.push(2);
	q.push(8);
	
	print(q);
	reverseQueue(q);
	cout<<"\n";
	print(q);
	return 0;
}
