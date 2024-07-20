#include<iostream>
using namespace std;
void printDigits(int n){
	if(n==0){
		cout<<"0\n";
		return;
	}
	int s=n%10;
	printDigits(n/10);
	cout<<s<<endl;
	
}

int main(){
	int n=647;
	printDigits(n);
	return 0;
}
