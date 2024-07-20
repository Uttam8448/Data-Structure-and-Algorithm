#include<iostream>
using namespace std;
class abc{
	int x;  //if x declared as mutable int gthen its value can be changed into a const function/method
	int *y;
	const int z;
	public:
//		abc(int a,int b,int c=0/*default aruguement*/){
//			x= a;
//			y= new int(b);
//			z=c;
//		}
//init list used do initilize const member variable also
	 	abc(int _x, int _y,int _z=0) : x(_x),y(new int(_y)), z(_z){
			cout<<"in init list"<<endl;
		}
		
//		abc(){
//			x=0;
//			y= new int(0);
//		}
		int getX() const{
		//	x=20;				//nhi chalega as const method me member vriable cant be updated
		//x value can be changed if x is declared as mutable first
			return x;
		}
		void setX(int val){
			x=val;
		}
		int getY() const{
//			int f=20;
//			y=&f;				//wont work as const function me member variable pointer cant be updated also..
			return *y;
		}
		void setY(int val){
			*y=val;
		}
		int getZ() const/*If constant not declared then call from printABC wont work as printABC parameter of abc obj is const func and if getZis not a const their is chance of updation thus compiler gives error!!*/
		{
		//	x=20;				//nhi chalega as const method me member vriable cant be updated
			return z;
		}
};
void printABC(const abc &a){
			cout<<a.getX()<<" "<<a.getY() <<" "<<a.getZ();
		}
int main(){
	abc a(1,2);
	printABC(a);
	return 0;
}





int main2(){
	const int x=5;
//	//manipulation of const not work in modern compilers
//	int *p=&x;
//	*p = 10;
//	cout<<x<<endl;
	//const with pointer
	//1.const data, non-const pointer.
//	const int *a=new int(2); 
////	int const *a=new int(2); //same as above
////	*a=20;					//cant change the data at a			
//	cout<<"Before address reallocation:"<<*a<<endl;
//	int b=5;	
//	a=&b;					//pointer itself can be reassigned
//	cout<<"After address reallocation:"<<*a<<endl;
	
	//2.CONST Pointer but non-const data
//	int* const a = new int(2);
//	cout<< *a << endl;
//	*a = 20;				//data manipulated
//	cout<< *a << endl;
//	int b = 50;
////	a = &b;				//nhi chalega, const pointer
	
	//3.CONST Pointer and CONST Data
//	const int* const a= new int (10);
//	cout<< *a <<endl;
//	*a = 50;				//nhi chalega, const data
//	int b= 100;
//	a = &b;					//nhi chalega, const pointer
	return 0;
}
