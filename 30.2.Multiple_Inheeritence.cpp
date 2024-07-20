//#include<iostream>
//using namespace std;
//class A{
//	public:
//		int physics;
//};
//class B{
//	public:
//		int chemistry;
//};
//class C:public A,public B{
//	public:
//		int maths;
//};
//int main(){
//	C obj;
//	cout<<obj.physics<<" "<<obj.chemistry<<" "<<obj.maths<<endl;;
//	return 0;
//}
//diamond problem
#include<iostream>
using namespace std;
class A{
	public:
		int physics;
		int chemistry;
		A(){
			chemistry=101;
		}
};
class B{
	public:
		int chemistry;
		B(){
			chemistry=201; 
		}
};
class C:public A,public B{
	public:
		int maths;
};
int main(){
	C obj;
	cout<<obj.physics<<" "<<obj.A::chemistry<<" "<<obj.B::chemistry<<" "<<obj.maths<<endl;;
	return 0;
}
