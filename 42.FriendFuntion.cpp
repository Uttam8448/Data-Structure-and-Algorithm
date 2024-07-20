#include<iostream>
using namespace std;
class A{
	private:
		int x;
	public:
		A(int _val) : x(_val){
		};
		int getX() const {return x;}
		void setX(int _val1){ x=_val1;
		}
		friend class B;	//friend class
		friend void print(const A&a);		//friend to function
};

class B{
	public:
		void print(const A &a){
			//cout<<a.getX()<<endl; //const parameter needs const function where it is declared
			cout<<a.x<<endl;
		}
};
	
void print(const A &a){
			//cout<<a.getX()<<endl; //const parameter needs const function where it is declared
			cout<<a.x<<endl;
		}
int main(){
	A a(5);
	B b;
	b.print(a);
	print(a);
	return 0;
	
}
