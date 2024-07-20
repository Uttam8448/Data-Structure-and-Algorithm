#include<iostream>
using namespace std;
void printPermutation(string &str,int i){
	if(i>=str.length()-1)
	{	cout<<str<<" ";
		return;
	}
	//swapping
	for(int j=i;j<str.length();j++){
		swap(str[i],str[j]);
		printPermutation(str,i+1);
		//to recreate the original input
		swap(str[i],str[j]); 
	}
}
int main(){
	string str="abc";
	int i=0;
	printPermutation(str,i);
	return 0;
	
}
