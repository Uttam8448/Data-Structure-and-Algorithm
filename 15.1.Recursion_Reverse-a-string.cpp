#include<iostream>
using namespace std;
void reverse(string& str,int s,int e){
	if(s>=e){
		return;
	}
	reverse(str,s+1,e-1); 
	swap(str[s],str[e]);
}
int main(){
	string str="babbar";
	int s=0;
	int e=str.size()-1;
	cout<<str<<endl;
	reverse(str,s,e);
	cout<<str;
	return 0;
}
