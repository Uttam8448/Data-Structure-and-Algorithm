 #include<iostream>
 using namespace std;
 int x=2;	//Global variable
 void fun(){
 	int x = 60;
 	cout<< x<<endl;
 	::x=40;
 	cout<<::x<<endl;k
 }
 int main(){
// 	cout<<x<<endl;
	::x=4;	//global x updated
	int x=20;	//local  x;
	cout<<x<<endl;		//local x
	cout<<::x<<endl;	//global x
	{
		int x=50;
		cout<<x<<endl;	//most local is 50
		cout<<::x<<endl;	//Global can be accessed but local with 20 value camt be accessed no method
	}
 	return 0;
 }
