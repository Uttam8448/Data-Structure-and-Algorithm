#include<iostream>
using namespace std;
int* solve(int* p){
	p=p+2;
	return p;
}
int* solve1(){
	int s=90;
	int* ptr=&s;
	return ptr;
}
int main(){
	int a=20;
	int* ptr=&a; 
	cout<<"Before: "<<ptr;
	ptr=solve(ptr);
	cout<<"\nAfter: "<<ptr;
	ptr=solve1();
	cout<<"\nAfter solve1 fumc: "<<ptr;
	cout<<"\n"<<*ptr;
	return 0;
}
