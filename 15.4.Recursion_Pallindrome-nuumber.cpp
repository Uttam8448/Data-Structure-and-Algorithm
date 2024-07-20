#include<iostream>
using namespace std;
bool solve(string& str,int i,int j){
	if(i>=j){
		return true;
	}
	if(str[i]!=str[j]){
		return false;
	}
	solve(str,++i,--j);
}
int main(){
	string str;
	int i=0;
	cin>>str;
	int j=str.size()-1;
	cout<<solve(str,i,j);
	return 0;
}
