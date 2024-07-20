#include<iostream>
using namespace std;
class Math{
	public:
		int sum(int a,int b){
			cout<<"First Function\n";
			return a+b;
		}
		int sum(int a,int b,int c){
			cout<<"Second Function\n";
			return a+b+c;
		}
		float sum(int a,float b){			//function overloading is done onnly using parameter
											//game not the return typee one it gives error
			cout<<"Third Function\n";
			return a+b;
		}
};
int main(){
	Math obj;
	cout<<obj.sum(2,5)<<endl;
	cout<<obj.sum(2,3,4)<<endl;
//	cout<<obj.sum(2,3.4)<<endl;    Error as compiler sense 3.4 as double not as float
	cout<<obj.sum(2,3.4f)<<endl;	//works
	return 0;
}
