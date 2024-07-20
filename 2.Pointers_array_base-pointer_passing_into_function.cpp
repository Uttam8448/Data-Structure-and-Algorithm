#include<iostream>
using namespace std;
void solve(int arr[]){
	cout<<"size of arr inside the solve function :"<<sizeof(arr);
	cout<<"\narr: "<<arr<<endl;
	cout<<"&arr: "<<&arr <<endl<<endl;
	arr[0]=50;
}
int main(){
	int arr[10]={1,2,3,4};
	cout<<"size of array inside the main function :"<<sizeof(arr)<<endl;
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	cout<<endl<<"Now calling solve function"<<endl;
	solve(arr);
	cout<<"Wapis main function me aagye hai"<<endl;
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	return 0;
}
