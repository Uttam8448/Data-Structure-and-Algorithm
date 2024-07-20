#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	cout<<"Deleting the front element :"<<q.front();
	q.pop();
	cout<<"\nSize of queue is :"<<q.size();
	if(q.empty()){
		cout<<"\nQueue is Empty!!";
	}
	else{
		cout<<"\nQueue is not  empty";
	}
	return 0;
}
