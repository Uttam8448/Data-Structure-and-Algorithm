#include<iostream>
using namespace std;
int fib(int n){
	if(n==2 ){
		return 1;
	}
	if(n==1){
		return 0;
	}
	return (fib(n-1)+fib(n-2));
}
int main(){
	int c;
	cout<<"Enter the nth no of fibonacci you want to search for: ";
	cin>>c;
	int ans=fib(c);
	cout<<ans;
	return 0;
	
}
