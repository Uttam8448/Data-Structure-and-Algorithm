#include<iostream>
using namespace std;
int main(){
	char ch[10]="Babbar";		//character array and pointer to it
	char* c=ch;
	
	cout<<"ch-"<<ch<<endl;
	cout<<"&ch-"<<&ch<<endl;
	cout<<"ch[0]-"<<ch[0]<<endl;
	
	cout<<"&c-"<<&c<<endl;
	cout<<"*c-"<<*c<<endl;
	cout<<"c-"<<c<<endl<<endl<<endl;
	
	char name[10]="Sher bano";		//character array and pointer to it
	char* cptr=&name[0];
	
	cout<<"name-"<<name<<endl;
	cout<<"&name-"<<&name<<endl;
	cout<<"*(name+3)"<<*(name+3)<<endl;
	
	
	cout<<"cptr-"<<cptr<<endl;
	cout<<"&cptr-"<<&cptr<<endl;
	cout<<"*(cptr+3)-"<<*(cptr+3)<<endl;
	cout<<"(cptr+2)-"<<cptr+2<<endl;
	cout<<"(*cptr)-"<<*cptr<<endl;
	cout<<"cptr+8-"<<cptr+8<<endl<<endl<<endl;
	
	char s='k';
	char* sptr=&s;
	
	cout<<sptr<<endl;

	
	return 0;
}
