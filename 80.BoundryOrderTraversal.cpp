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
void printLeft(node* root){
	if(root==NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		return;
	cout<<root->data<<" ";
	if(root->left == NULL)
		printLeft(root->right);
	else{
		printLeft(root->left);
	}
}
void printLeaf(node* root){
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		cout<<root->data<<" ";
	printLeaf(root->left);
	printLeaf(root->right);
}
void printRight(node* root){
	if(root==NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		return;
	if(root->right == NULL)
		printRight(root->left);
	printRight(root->right);
	cout<<root->data<<" ";
}
/*
Enter the data:
10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
Enter data for inserting in left 10
Enter the data:
Enter data for inserting in left 20
Enter the data:
Enter data for inserting in left 40
Enter the data:
Enter data for inserting in right of 40
Enter the data:
Enter data for inserting in right of 20
Enter the data:
Enter data for inserting in left 50
Enter the data:
Enter data for inserting in left 70
Enter the data:
Enter data for inserting in left 110
Enter the data:
Enter data for inserting in right of 110
Enter the data:
Enter data for inserting in right of 70
Enter the data:
Enter data for inserting in left 111
Enter the data:
Enter data for inserting in right of 111
Enter the data:
Enter data for inserting in right of 50
Enter the data:
Enter data for inserting in left 80
Enter the data:
Enter data for inserting in right of 80
Enter the data:
Enter data for inserting in right of 10
Enter the data:
Enter data for inserting in left 30
Enter the data:
Enter data for inserting in right of 30
Enter the data:
Enter data for inserting in left 60
Enter the data:
Enter data for inserting in right of 60
Enter the data:
Enter data for inserting in left 90
Enter the data:
Enter data for inserting in left 112
Enter the data:
Enter data for inserting in right of 112
Enter the data:
Enter data for inserting in right of 90
Enter the data:
Enter data for inserting in left 113
Enter the data:
Enter data for inserting in right of 113
Enter the data:
10 20
40 110 111 80 112 113
90 60 30 10*/
void boundryTraversal(node* root){
	printLeft(root);
	printLeaf(root);
	if(root->right)
		printRight(root->right);
	else
		printRight(root->left);
}
/*
Enter the data:
10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
Enter data for inserting in left 10
Enter the data:
Enter data for inserting in left 20
Enter the data:
Enter data for inserting in left 40
Enter the data:
Enter data for inserting in right of 40
Enter the data:
Enter data for inserting in right of 20
Enter the data:
Enter data for inserting in left 50
Enter the data:
Enter data for inserting in left 70
Enter the data:
Enter data for inserting in left 110
Enter the data:
Enter data for inserting in right of 110
Enter the data:
Enter data for inserting in right of 70
Enter the data:
Enter data for inserting in left 111
Enter the data:
Enter data for inserting in right of 111
Enter the data:
Enter data for inserting in right of 50
Enter the data:
Enter data for inserting in left 80
Enter the data:
Enter data for inserting in right of 80
Enter the data:
Enter data for inserting in right of 10
Enter the data:
Enter data for inserting in left 30
Enter the data:
Enter data for inserting in right of 30
Enter the data:
Enter data for inserting in left 60
Enter the data:
Enter data for inserting in right of 60
Enter the data:
Enter data for inserting in left 90
Enter the data:
Enter data for inserting in left 112
Enter the data:
Enter data for inserting in right of 112
Enter the data:
Enter data for inserting in right of 90
Enter the data:
Enter data for inserting in left 113
Enter the data:
Enter data for inserting in right of 113
Enter the data:
Boundry traversal: 
10 20 40 110 111 80 112 113 90 60 30 
*/
int main(){
	node* root = NULL;
	root=buildTree(root);
	boundryTraversal(root);
	return 0;
}
