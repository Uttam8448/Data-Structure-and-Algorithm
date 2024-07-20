#include<iostream>
using namespace std;
int lastOccur(string& str,int i,char key,int& ans){
	if(i>= str.size()){
		return ans;
	}
	if(str[i]==key){
		ans=i;
	}
	lastOccur(str,++i,key,ans);
}
int main(){
	string str;
	int ans=-1;
	int i=0;
	char key;
	cin>>str>>key;
	cout<<lastOccur(str,i,key,ans);
	
}
