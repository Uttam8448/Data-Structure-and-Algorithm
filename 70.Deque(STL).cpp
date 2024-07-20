#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int> dq;
	dq.push_front(5);
	dq.push_front(10);
	dq.push_front(20);
	dq.push_back(30);
	
	cout<<"Size: "<<dq.size()<<endl;
	dq.pop_front();
	cout<<"Size: "<<dq.size()<<endl;
	dq.pop_back();
	cout<<"Size: "<<dq.size()<<endl;
	cout<<"Front Element : "<<dq.front();
	cout<<"\nBack Element : "<<dq.back();
	if(dq.empty()){
		cout<<"\nEmpty!!";
	}
	else{
		cout<<"\Not Empty";
	}
	return 0;
		
}
