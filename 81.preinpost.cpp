#include<iostream>
#include<queue>
#include<stack>
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
node* buildTree(node* root){
		cout<<"Enter the data: " <<endl;
		int data;
		cin>>data;
		root = new node(data);
		if(data==-1){
			return NULL;
		}
		cout<<"Enter data for inserting in left " <<data<<endl;
		root->left = buildTree(root->left);
		cout<<"Enter data for inserting in right of "<<data << endl;
		root->right = buildTree(root->right);
		return root;
	}
void inprepost(node* root,vector<int>& preOrder,vector<int>& inOrder,vector<int>& postOrder){
	if(!root)
		return;
	preOrder.push_back(root->data);
	inprepost(root->left,preOrder,inOrder,postOrder);
	inOrder.push_back(root->data);
	inprepost(root->right,preOrder,inOrder,postOrder);
	postOrder.push_back(root->data);
}
void print(vector<int> temp){
	for(int i=0;i<temp.size();i++){
		cout<<temp[i]<<" ";
	}
}
int main(){
	node* root;
	root=buildTree(root);
	vector<int> preOrder;
	vector<int> inOrder;
	vector<int> postOrder;
	inprepost(root,preOrder,inOrder,postOrder);
	cout<<"PreOrder :";
	print(preOrder);
	cout<<"\nInOrder :";
	print(inOrder);
	cout<<"\nPostOrder :";
	print(postOrder);
	return 0;
}
/*
Enter the data:
1
Enter data for inserting in left 1
Enter the data:
2
Enter data for inserting in left 2
Enter the data:
3
Enter data for inserting in left 3
Enter the data:
-1
Enter data for inserting in right of 3
Enter the data:
-1
Enter data for inserting in right of 2
Enter the data:
4
Enter data for inserting in left 4
Enter the data:
-1
Enter data for inserting in right of 4
Enter the data:
-1
Enter data for inserting in right of 1
Enter the data:
5
Enter data for inserting in left 5
Enter the data:
-1
Enter data for inserting in right of 5
Enter the data:
6
Enter data for inserting in left 6
Enter the data:
-1
Enter data for inserting in right of 6
Enter the data:
-1
PreOrder :  1 2 3 4 5 6
InOrder :   3 2 4 1 5 6
PostOrder : 3 4 2 6 5 1
*/
