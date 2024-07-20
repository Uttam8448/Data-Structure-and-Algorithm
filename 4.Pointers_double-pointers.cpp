#include <iostream>
using namespace std;
void util(int* p ){
	p=p+1;
}
int main()
{
	int a=10;
	int* p=&a;
	int** q=&p;
	
	cout<<&a<<endl;
	cout<<a<<endl;
	cout<<p<<endl;
	cout<<&p<<endl;
	cout<<*p<<endl;
	cout<<q<<endl;
	cout<<&q<<endl;
	cout<<*q<<endl;
	cout<<**q<<endl;
	
	int c=5;
	int *b=&a;
	cout<<"Before function: \n"<<c<<endl;
	cout<<b<<endl;
	cout<<*b<<endl;
	
	util(b);
	cout<<"After the function: \n"<<c<<endl;
	cout<<b<<endl;
	cout<<*b<<endl;
	return 0;
}

