#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<char> str;
	int size;
	cout<<"Enter the size of string you want to insert as an input :";
	cin>>size;
	cout<<"Enter String :";
	while(size!=0){
		char temp;
		cin>>temp;
		str.push(temp);
		size--;
	}
	cout<<"Reversed String: ";
	while(!str.empty()){
		cout<<str.top();	
		str.pop();
		}
}
