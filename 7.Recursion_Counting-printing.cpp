#include<iostream>
using namespace std;
void printcountingreverse(int n){
	//base case
	if(n==0){
		return;
	}
	
	cout<<n<<" ";
	printcountingreverse(n-1);
	
}
void printcounting(int n){
	//base case
	if(n==0){
		return;
	}
	printcounting(n-1);
	cout<<n<<" ";
	
}

int main(){
	int n;
	cout<<"enter the value of n: ";
	cin>>n;
	cout<<"Calling Printcount function: \n";
	printcounting(n);
	cout<<"\nCalling Printcountreverse function: \n";
	printcountingreverse(n);
	return 0;
}
