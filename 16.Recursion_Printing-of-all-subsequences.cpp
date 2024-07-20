#include<iostream>
using namespace std;
void printSubsequences(string str,string outstr,int i){
	if(i>=str.length()){
		cout<<outstr<<endl;
		return;
	}
	//exclude
	printSubsequences(str,outstr,i+1);
	
	//include
	outstr.push_back(str[i]);
	printSubsequences(str,outstr,i+1); 
}
int main(){
	string str="abc";
	cout<<str.length();
	int i=0;
	string outstr="";
	printSubsequences(str,outstr,i);
	return 0;
}
