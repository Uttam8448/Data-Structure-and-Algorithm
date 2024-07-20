
//VirtualConstructor is not possible
// #include<iostream>
// using namespace std;
// class Base{
// 	public:
// 		/*virtual*/ Base(){		//not allowed
// 			cout<<"Base ctor\n";
//		 }
//		~Base(){
//			cout<<"Base dtor\n";
//		}
// };
// class Derived : public Base{
// 	public:
// 		Derived(){
// 			cout<<"Derived ctor\n";
//		 }
//		~Derived(){
//			cout<<"Derived dtor\n";
//		}
// };
// int main(){
// 	Base *b = new Derived();
// 	delete b;
// 	return 0;
// }
// 
 //Virtual Destructor is possible
  #include<iostream>
 using namespace std;
 class Base{
 	public:
 		Base(){		//not allowed
 			cout<<"Base ctor\n";
		 }
		//if not used virtual then base and derived constructor and only base destructor gets called
 		virtual ~Base(){
			cout<<"Base dtor\n";
		}
 };
 class Derived : public Base{
 	public:
 		int *a;
 		Derived(){
 			a=new int[100];
 			cout<<"Derived ctor\n";
		 }
		~Derived(){
			delete[] a;
			cout<<"Derived dtor\n";
		}
 };
 int main(){
 	Base *b = new Derived();
 	delete b;
 	return 0;
 }
//if used virtual destructor in base destructor
//Base ctor
//Derived ctor
//Derived dtor
//Base dtor
