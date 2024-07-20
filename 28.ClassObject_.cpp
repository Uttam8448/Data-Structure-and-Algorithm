#include<iostream>
using namespace  std;
class Animal{
	public:
	int age;
	int weight;
	string type;
	//default  constructor
	Animal() {
		this->weight=0;
		this->age=0;
		this->type="";
		cout<<"Constructor\n";
	}
	//copy constructor
	Animal(Animal &obj){
		this->age=obj.age;
		this->type=obj.type;
		this->weight=obj.weight;
		cout<<"Copy Constructor\n";
	}
	void fun(){
		
	}
	~Animal() {
		cout<<"I am a Destructor\n";
	}
};
int main(){
	Animal* suresh = new Animal;
	(*suresh).age=15;
	(*suresh).type="billi";
	 Animal ramesh(*suresh);
	 Animal kamlesh(ramesh);
	Animal* b=new Animal;
	b->age=12;
	delete b;
	return 0;
}
