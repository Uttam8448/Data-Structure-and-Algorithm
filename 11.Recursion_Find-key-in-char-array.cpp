#include<iostream>
using namespace std;
bool checkkey(char arr[],int n,char key,bool& b){
	if(n==0){
		return b;
	}
	if(arr[0]==key){
		b=true;
		return b;
	}
	checkkey(arr+1,n-1,key,b);
}
bool checkkey1(char arr[],int n,char key){
	if(n==0){
		return false;
	}
	if(arr[0]==key){
		return true;
	}
	checkkey1(arr+1,n-1,key);
}
bool checkkey2(string& str,int i,int& n,char& key){
	if(i>=n){
		return false;
	}
	if(str[i]==key){
		return true;
	}
	checkkey2(str,++i,n,key);
}
int main(){
	char arr[]="lovebabbar";
	bool b=false;
	char key='r';
	checkkey(arr,sizeof(arr),key,b);
	cout<<"\nPresent: "<<b;
	cout<<"\nPresent: "<<checkkey1(arr,sizeof(arr),key);
	string str="lovebabbar";
	int n2=10;
	char key2='u';
	cout<<"\nPresent: "<<checkkey2(str,0,n2,key2);
	return 0;
	
	
}
