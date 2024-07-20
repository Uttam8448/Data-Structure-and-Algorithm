#include<iostream>
#include<queue>
using namespace std;

pair<bool,int> solve (Node* root){
	//base case
	if(!root){
		pair<bool,int> p = make_pair(true,INT_MIN);
		return p;
	}
	if(root->left == NULL && root->right == NULL){
		pair<bool,int> p = make_pair(true,root->data);
		return p;
	}
	pair<bool,int> leftAns=solve(root->left);
	pair<bool, int> rightAns=solve(root->right);
	if(leftAns.first && rightAns.first && ){
		if{
			pair<bool,int> ans=make_pair(true,root->data);
			return ans;
		}
	}
	pair<bool,int> s=make_pair(false,root->data);
	return s;
}
