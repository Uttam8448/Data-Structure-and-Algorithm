#include<iostream>
#include<queue>
using namespace std;
//queue<int> interleaveHalves(queue<int> &q){
//	queue<int> n;
//	int half=q.size()/2;
//	for(int i=1;i<=half;i++){
//		int ele=q.front();
//		q.pop();
//		n.push(ele);
//	}
//	queue<int> ans;
//	for(int i=1;i<=half;i++){
//		ans.push(n.front());
//		ans.push(q.front());
//		q.pop();
//		n.pop();
//	}
//	return ans;
//}
void interleaveHalves(queue<int> &q){
	queue<int> n;
	int half=q.size()/2;
	for(int i=1;i<=half;i++){
		int ele=q.front();
		q.pop();
		n.push(ele);
	}
	for(int i=1;i<=half;i++){
		q.push(n.front());
		q.push(q.front());
		q.pop();
		n.pop();
	}
	if(q.size()%2!=0){
		q.push(q.front());
		q.pop();
	}
}
void print(queue<int> q){
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	cout<<endl;
}
int main(){
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	q.push(80);
	print(q);
	interleaveHalves(q);
	print(q);
	return 0;
}
