//#include<iostream>
//using namespace std;
//class abc{
//	public:
//	int x,y;
//	
////	void print() const{
////		cout<<x<<" "<<y<<endl;
////	}
////same output 
//	void print() const{
//		cout<<this->x<<" "<<this->y<<endl;
//	}
//};
//int main(){
//	abc obj1={1,2};
//	abc obj2 = {4,5};
//	obj1.print();
//	obj2.print();
//	return 0;	
//}

//#include<iostream>
//using namespace std;
//class abc{
//	public:
//	static int x,y;
//	
////	void print() const{
////		cout<<x<<" "<<y<<endl;
////	}
////same output 
//	void print() const{
//		cout<<x<<" "<<y<<endl;
//	}
//};
////static member variables
//int abc::x;		//if static variables is not declared then instance would get error for accessing
//int abc::y;
//int main(){
//	abc obj1;
//	obj1.x=1;
//	obj1.y=2;
//	obj1.print();
//	abc obj2;
//	obj1.x=10;
//	obj1.y=20;
//	obj1.print();
//	obj2.print();
//	return 0;	
//}

#include<iostream>
using namespace std;
class abc{
	public:
	static int x,y;
	
//	void print() const{
//		cout<<x<<" "<<y<<endl;
//	}
//same output 
	static void print()  {
		cout<<x<<" "<<y<<endl;	//if x and y weren't static error will be generated as no hidden this pointer is passed into static member fuction unlike to normal member function
	}
};
//static member function
int abc::x;		//if static variables is not declared then instance would get error for accessing
int abc::y;
int main(){
	abc obj1;
	obj1.x=1;
	obj1.y=2;
	abc::print();
	abc obj2;
	obj1.x=10;
	obj1.y=20;
	obj1.print();
	obj2.print();
	return 0;	
}
