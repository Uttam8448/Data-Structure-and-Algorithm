#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<vector<int>> arr(6,vector<int>(6,0));
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}	\
	for(int i=0;i<6;i++){
	    delete []arr[i];
	}
	delete []arr;
	return 0;
}
