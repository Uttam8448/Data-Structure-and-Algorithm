#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKelementQueue(queue<int> &q,int &k){
	stack<int> s;
	int n=k;
	//Step 1: Put k elements of q into stack
	while(k!=0){
		int element=q.front();
		q.pop();
		s.push(element);
		k--;
	}
	
	//Step 2: Put all elements of stack into q
	while(!s.empty()){
		int element=s.top();
		s.pop();
		q.push(element);
	} 
	//Step 3: Pop and push again element into queue size - k elements
	while(q.size()-n!=0){
		int element=q.front();
		q.pop();
		q.push(element);
		n++;
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
	int k=5;
	print(q);
	reverseKelementQueue(q,k);
	cout<<"\n";
	print(q);
	return 0;
}
