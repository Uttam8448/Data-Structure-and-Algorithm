#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int x,int y,int z){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
//	int a=0;
//	if(n-x>=0){								//1case solve kiya hai
//		a=solve(n-x,x,y,z)+1;
//	}
//	int b=0;
//	if(n-y>=0){
//		b=solve(n-y,x,y,z)+1;
//	}
//	int c=0;
//	if(n-z>=0){
//		
//		c=solve(n-z,x,y,z)+1;
//	}
	int a = solve(n-x, x,y,z) + 1;

	int b = solve(n-y, x,y,z) + 1;

	int c = solve(n-z, x,y,z) + 1;

	int ans=max(a,max(b,c));
	return ans;
}
int main(){
	int n=8;
	int x=5;
	int y=2;
	int z=1;
	int ans=solve(n,x,y,z);
	if(ans<0)
		ans = 0;
	cout<<"Answer is: " <<ans<<endl;
	
	return 0;
}
