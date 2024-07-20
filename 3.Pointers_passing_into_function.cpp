#include<iostream>
using namespace std;
void update(int *p){
	cout<<"Inside the update function:\n";
	cout<<"Address stored intside p is: "<<p<<endl;
	cout<<"Address of p is: "<<&p <<endl;
	*p=*p+10;
}
int main(){
	int a=5;
	cout<<"Inside the main function:\n";
	cout<<"Address of a is: "<<&a<<endl;
	int* ptr = &a;
	cout<<"address stored in ptr is: "<<ptr <<endl;
	cout<<"address of ptr is: "<<&ptr <<endl;
	update(ptr);
	cout<<"Inside the main function:\n";
	cout<<"value of a is: "<<a<<endl;
	return 0;
}
