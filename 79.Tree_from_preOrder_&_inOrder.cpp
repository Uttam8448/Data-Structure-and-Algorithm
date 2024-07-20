#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* left;
	node* right;
	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
int searchInorder(int inOrder[],int size, int target){
	for (int i=0;i<size;i++){
		if(inOrder[i] == target)
			return i;
	return -1;
	}
}
node* Solve(int inOrder[],int preOrder[],int size,int& preIndex,int inOrderStart,int inOrderEnd){
	// base case
	if(preIndex >= size || inOrderStart > inOrderEnd ){
		return NULL;
	}
	 
	int element = preOrder[preIndex];
	preIndex++;
	node* root = new node(element); 
	//element search krna padega inorder me
	int position = searchInorder(inOrder,size,element);
	root->left = Solve(inOrder,preOrder,size,preIndex,inOrderStart,position-1);
	root->right = Solve(inOrder,preOrder,size,preIndex,position+1,inOrderEnd);
	
}
int main(){
	int inorder[]={10,8,6,2,4,12};
	int preorder[]={2,8,10,6,4,12};
	int size=6;
	int preOrderIndex = 0;
	int inOrderIndexStart = 0;
	int inOrderIndexEnd = 5;
	
	return 0;
}
