#include<iostream>
#include<queue>

using namespace std;
int getKthSmallestElement(int arr[],int n,int k){
	//create max heap
	priority_queue<int> pq;
	//insert initial k elements of array
	for(int i=0;i<k;i++){
		pq.push(arr[i]);
	}
	for(int i=k;i<n;i++){
		if(pq.top()>arr[i]){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	return pq.top();
}


int main(){
	int arr[]={10,5,20,4,15};
	int n=5;
	int k=2;
	int ans=getKthSmallestElement(arr,n,k);
	cout<<ans;
	return 0;	
}
