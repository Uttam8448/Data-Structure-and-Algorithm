#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<int> v(5);
	v[0]=3;
	v[1]=4;
	v[2]=0;
	v[3]=1;
	v[4]=2;
	sort(v.begin(),v.end());
	for(auto i : v){
		cout<< i <<endl;
	}
	sort(v.begin(),v.end());
	sort(v.begin(),v.end());	
	
	return 0;
}
