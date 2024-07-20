#include<iostream>
using namespace std;
class abc{
	public:
		int x;
		int *y;
		//default dumb copy constructor
		abc(const abc &obj){
			x=obj.x;
			y=obj.y;
		}
		//Our smart deep copy
//		abc(const abc &obj){
//		x= obj.x;
//		y= new int(*obj.y);
//		}
		abc(int _x, int _y) : x(_x), y(new int (_y)) {}
		void print() const
		{
			printf("X:%d\nPTR Y:%p\nContent of Y(*Y):%d\n\n", x, y,*y);
		}
		~abc(){
			delete y;
		}
};

int main(){
//	abc a(1,2);
//	a.print();
//	abc b=a;	//abc b(a);
//	b.print();	//pointer y pointing is also same for object a 
//problem with shallow copy....	
	abc *a = new abc(1,2);
	abc b=*a;
	b.print();
	delete a;
	b.print();
//	delete b;	//gives double free error on shallow copy
	return 0;	
}
