#include<iostream>
using namespace std;
int lastOccur(string& str,int i,char& key){
	if(str[i]==key || i<0){
		return i;
	}
	lastOccur(str,i-1,key);
}
int main(){
	string str;
	char key;
	cin>>str>>key;
	int i=str.size()-1;
	cout<<lastOccur(str,i,key);
	return 0;
}
