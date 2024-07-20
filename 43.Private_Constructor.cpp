#include<iostream>
using namespace std;
class Box{
	int width;
	Box(int _v): width(_v){};
	public:
		int GetWidth() const{
			return width;
		}
		void SetWidth(int _val){
			width = _val;
		}
		friend class BoxFactory;
};
class BoxFactory{
	int count=0;
	public:
		Box getAbox(int _w){
			count++;				//to count no of boxes 
			return Box(_w);
		}
};
int main(){
//	Box b(5);					//wont work as private constructor
//	cout<<b.GetWidth()<<endl;
	BoxFactory a;
	Box x=a.getAbox(5);
	cout<<x.GetWidth();
	return 0;
}
