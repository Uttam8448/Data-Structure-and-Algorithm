#include<iostream>
using namespace std;
int factorial(int n){
	cout<<"Function is called for "<<n<<"\n";
	//base case
	if(n==1){
		return 1;
	}
	int chotiproblemans=factorial(n-1);
	int badiproblemans=n*chotiproblemans;
	return badiproblemans;	//if this is not returned then also code works
}
int main(){
	int n;
	cout<<"Enter the value of n : ";
	cin >> n;
	int ans=factorial(n);
	cout<<"Answer is: "<< ans<<endl;
	return 0;
}
