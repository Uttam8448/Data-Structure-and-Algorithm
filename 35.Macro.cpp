#include<iostream>
using namespace std;
//float circleArea(float r){
//	return 3.14 * r * r;
//}
#define PI 3.14159465			//macro 
#define MAXX(x , y) (x>y ? x : y)
float circleArea(float r){
	return PI * r * r;
}
float circlePerimeter(float r){
	return 2 * PI * r;
}
void fun(){
	int x=6;
	int y=17;
	int z=MAXX(x,y);
	cout<<z<<endl;
}
void fun1(){
	int x=5;
	int y=4;
	int z=MAXX(x,y);
	cout<<z<<endl;
}

int main(){
	cout<<circleArea(65.4) << endl;
	cout<<circlePerimeter(65.4) << endl; 
	fun1();
	fun();
	return 0;
}
