#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data) {
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};
Node* insertIntoBST(Node* &root,int data) {
	if(root == NULL) {
		//this is the first node we have to create
		root=new Node(data);
		return root;
	}
	if(root->data>data){
		//insert into left
		insertIntoBST(root->left,data);
	}
	else{
		//insert into right
		insertIntoBST(root->right,data);
	}
	return root;
}
void takeInput(Node* &root) {
	int val;
	cin>>val;
	
	while(val != -1){
		insertIntoBST(root,val);
		cin >> val;
	}
}
void levelOrderTraversal(Node* root){
	queue<Node* > q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp == NULL) {
			//purana level complete traverse ho chuka hai
			cout<<endl;
			if(!q.empty()){
				//queue still has same child nodes
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
bool search(Node* root,int target){
	if(root==NULL){
		return false;
	}
	if(root->data==target){
		return true;
	}
	
	if(root->data > target){
		return search(root->left,target);
	}
	else if(root->data < target){
		return search(root->right,target);
	}
}
//int maxOfLeft(Node* root,max){
//	
//	if(root==NULL)
//		return max;
//	if(max<root->data)
//		max=root->data;
//	maxxOfLeft(root->left,max);
//	maxOfLeft(root->right,max);
//}
//int inorderPre(Node* root,int key){
//	if(root->data==key){
//		int max=0;
//		return maxOfLeft(root-->left,max);
//	}
//}

//Creating BST using Inorder traversal(sorted one)
Node* bstUsingInorder(int inorder[],int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	int element = inorder[mid];
	Node* root = new Node(element);
	root->left=bstUsingInorder(inorder,s,mid-1);
	root->right=bstUsingInorder(inorder,mid+1,e);
	return root;
	}
int main(){
//	10 20 5 11 17 2 4 8 6 25 15
//	Node* root=NULL;
//	cout<<"Enter the data for node "<<endl;
//	takeInput(root);
//	levelOrderTraversal(root); 
//	cout<<search(root,18);
	int inorder[]={1,2,3,4,5,6,7,8,9};
	Node* root=bstUsingInorder(inorder,0,8);
	levelOrderTraversal(root);
	return 0;
}
