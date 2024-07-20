#include<iostream>
#include<vector>
using namespace std;
void PrintSubArr(vector<int>& arr,int s,int e){
	if(e == arr.size()){
		return;
	}
	for(int i=s;i<=e;i++){
		cout<<arr[i];
	}
	cout<<endl;
	PrintSubArr(arr,s,e+1);
}
void PrintSubArray(vector<int>& arr,int s,int e){
	for(int i=0;i<arr.size();i++){
		PrintSubArr(arr,i,i);
	}
}
int main(){
	vector<int> nums(5);
	cin>>nums[0];
	cin>>nums[1];
	cin>>nums[2];
	cin>>nums[3];
	cin>>nums[4];
	int t=nums.size();
	PrintSubArray(nums,0,0);
	return 0;
}
