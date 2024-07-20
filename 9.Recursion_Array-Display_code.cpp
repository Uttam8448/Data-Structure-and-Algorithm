#include<iostream>
using namespace std;
void display(int arr[],int n,int i){
	if(i>=n){
		return;
	}
	cout<<arr[i]<<" ";		//1 case solve karna hai
	display(arr,n,i+1);
}
int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9};
	display(arr,10,0);
	return 0;	
 }
