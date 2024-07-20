#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmaller(vector<int> &arr) {
	stack<int> st;
	vector<int> ans(arr.size());
	st.push(-1);
	for(int i=0;i<arr.size();i++){
		int curr = arr[i];
		while(st.top()>=curr){
			st.pop();
		}
		ans[i] = st.top();
		st.push(curr);
	}
	return ans;
}


vector<int> nextSmaller(vector<int> &arr) {
	stack<int> st;
	vector<int> ans(arr.size());
	st.push(-1);
	for(int i=arr.size()-1;i>=0;i--){
		int curr = arr[i];
		while(st.top()>=curr){
			st.pop();
		}
		ans[i] = st.top();
		st.push(curr);
	}
	return ans;
}
vector<int> prevSmallerIndex(vector<int> &arr) {
	stack<int> st;
	vector<int> ans(arr.size());
	st.push(-1);
	for(int i=0;i<arr.size();i++){
		int curr = arr[i];
		while((st.top()==-1?-1:arr[st.top()])>=curr){
			st.pop();
		}
		st.top()==-1?ans[i] = -1:ans[i] = st.top();
		st.push(i);
	}
	return ans;
}


vector<int> nextSmallerIndex(vector<int> &arr) {
	stack<int> st;
	vector<int> ans(arr.size());
	st.push(-1);
	for(int i=arr.size()-1;i>=0;i--){
		int curr = arr[i];
		while((st.top()==-1?-1:arr[st.top()])>=curr){
			st.pop();
		}
		st.top()==-1?ans[i] = arr.size():ans[i] = st.top();
		st.push(i);
	}
	return ans;
}

void print(vector<int> &ans){
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}
}
int main()
{
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(2);
	arr.push_back(3);
	cout<<"Printing prev smaller element :"<<endl;
	vector<int> anselepre=prevSmaller(arr);
	print(anselepre);
	cout<<"\nPrinting next smaller element : "<<endl;
	vector<int> anselenext=nextSmaller(arr);
	print(anselenext);
	cout<<"\nPrinting prev smaller element index of array :"<<endl;
	vector<int> anseleindpre=prevSmallerIndex(arr);
	print(anseleindpre);
	cout<<"\nPrinting next smaller element index of array : "<<endl;
	vector<int> anseleindnext=nextSmallerIndex(arr);
	print(anseleindnext);
	return 0;
}
