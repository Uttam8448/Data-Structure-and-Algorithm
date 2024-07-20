#include<iostream>
#include<queue>
using namespace std;

void reverseQueueRecursion(queue<int> &q){
	if(q.empty()){
		return;
	}
	int element=q.front();
	q.pop();
	reverseQueueRecursion(q);
	q.push(element);
	
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
	reverseQueueRecursion(q);
	cout<<"\n";
	print(q);
	return 0;
}
