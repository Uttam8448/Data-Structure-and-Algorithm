#include<iostream>
#include<string>
using namespace std;
void PrintSubsequences(string str,string outstr,int i){
	if(i==str.size()){
		cout<<outstr<<endl;
		return;
	}
	outstr.push_back(str[i]);
	PrintSubsequences(str,outstr,i+1);
	outstr.pop_back();
	PrintSubsequences(str,outstr,i+1);
}
int main(){
	string str="abcd";
	int i=0;
	string outstr="";
	PrintSubsequences(str,outstr,i);
	return 0;
}
