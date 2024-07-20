#include<iostream>
using namespace std;
class param{
	public:
		int val;
		void operator + (param &b){
			cout<<this->val-b.val;
		}
		
};
int main(){
	param obj1,obj2;
	obj1.val= 7;
	obj2.val=2;
	//obj1+obj2 --->this should print difference between val of both object
	obj1+obj2;
	return 0;
}
