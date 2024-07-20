 #include<iostream>
 using namespace std;
 void maxi(int arr[],int n,int& max){
 	if(n==0){
 		return;
	 }
	 if(max<arr[0]){
	 	max=arr[0];
	 }
	 maxi(arr+1,n-1,max);
 }
 void mini(int arr[],int n,int& min){
 	if(n==0)
		return;
	if(min>arr[0]){
		min=arr[0];
	}
	mini(arr+1,n-1,min);
 }
 int main(){
 	int arr[]={2,3,1,5,6,90};
 	int max=INT_MIN;
 	int n=sizeof(arr)/4;
 	maxi(arr,n,max);
 	cout<<"Maximum element in array is: "<<max;
 	int min=INT_MAX;
 	mini(arr,n,min);
 	cout<<"\nMinimum element in array is: "<<min;
	return 0;
 }
