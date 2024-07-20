#include<iostream>
#include<vector>
using namespace std;
int isSorted(vector<int> arr,int n,int& i){
	if(n==i){
		return 1;
	}
	if(arr[i+1]<arr[i]){
		return 0;
	}
	return isSorted(arr,n,++i);
}
int main(){
	vector<int> arr(4);		//size should be declared to access through index that is declare using index
	arr[0]=10;
	arr[1]=30;
	arr[2]=40;
	arr[3]=80;
//	arr.push_back(10);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(80);

	int i=0;
	cout<<isSorted(arr,3,i);
	return 0;
} 
