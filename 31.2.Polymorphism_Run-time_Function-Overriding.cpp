//overriding function
//#include<iostream>
//using namespace std;
//class Animal{
//	public:
//		void speak() {
//			cout<<"Speaking in Animal\n";
//		}
//};
//class Dog:public Animal {
//	public:
//		//overeride
//		void speak(){
//			cout<<"Barking in Dog\n";
//		}
//};
//int main(){
//	 Animal a;
//	 a.speak();
//	 Dog d;
//	 d.speak();
//	
//	return 0;
//}
 
//using dynamic object
//#include<iostream>
//using namespace std;
//class Animal{
//	public:
//		void speak() {
//			cout<<"Speaking in Animal\n";
//		}
//};
//class Dog:public Animal {
//	public:
//		//overeride
//		void speak(){
//			cout<<"Barking in Dog\n";
//		}
//};
//int main(){
//	Animal* a = new Dog();
//	a->speak();
//	Dog* d =(Dog* ) new Animal();
//	d->speak();
//	return 0;
//}


//using virtual functions and dynamic object
//#include<iostream>
//using namespace std;
//class Animal{
//	public:
//		virtual void speak() {
//			cout<<"Speaking in Animal\n";
//		}
//};
//class Dog:public Animal {
//	public:
//		//overeride
//		void speak(){
//			cout<<"Barking in Dog\n";
//		}
//};
//int main(){
//	//Upcasting
//	Animal* a = new Dog();
//	a->speak();
//	
//	//Downcasting
//	Dog* d =(Dog* ) new Animal();
//	d->speak();
//	return 0;
//}

//Constructor costructor
#include<iostream>
using namespace std;
class Animal{
	public:
		Animal(){
			cout<<"I am inside Animal Constructor!!"<<endl;
		}
		virtual void speak() {
			cout<<"Speaking in Animal\n";
		}
};
class Dog:public Animal {
	public:
		Dog(){
			cout<<"I am inside Dog Constructor!!"<<endl;
		}
		//override
		void speak(){
			cout<<"Barking in Dog\n";
		}
};
int main(){
	Animal* a = new Animal();
	cout<<endl;
	Dog* b=new Dog();
	cout<<endl;
	Animal* c = new Dog();
	cout<<endl;
	Dog* d = (Dog* ) new Animal();
	cout<<endl;
	return 0;
}
