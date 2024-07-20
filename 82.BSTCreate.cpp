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

//Node* deleteNodeInBST(Node* root,int target) {
//	//base case
//	// 100 50 150 40 60 175 110 -1
//	if(!root) return root;
//	//Step-1
//	Node* temp=findNodeInBST(root,target);
//	//Case 1
//	if(!temp->left && !temp->right){
//		delete temp;
//		return NULL;
//	}
//	else if(!temp->left && temp->right){
//		Node* child=temp->right;
//		delete temp;
//		return child;
//	}
//	else if(temp->left && !temp->right){
//		Node* child=temp->left;
//		delete temp;
//		return child;
//	}
//	else{
//		//inorder predecessor of left subtree -->left subtree me max value
//		int inOrderPre = maxVal(temp->left);
//		temp->data = inOrderPre;
//		temp->left=deleteNodeInBST(temp->left,inorderPre);
//		return temp;
//	}
//}
int maxVal(Node* root){
	Node* temp = root;
	if(temp == NULL){
		return -1;
	}
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp->data;
}
Node* deleteNodeInBST(Node* root,int target){
	if(root==NULL)	return NULL;
	if(root->data == target){
		//isi ko delete krna hai
		//4 cases
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}
		else if(!root->left && root->right){
			Node* child=root->right;
			delete root;
			return child;
		}
		else if(root->left && !root->right){
			Node* child = root->left;
			delete root;
			return child;
		}
		else{
			//both child
			//find inorder predecessor into left subtree
			int inorderPre = maxVal(root->left);
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
		}
	}
	else if(target > root -> data) {
		root->right= deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		root->left= deleteNodeInBST(root->left, target);
	}
	return root;
}
int main(){
//	10 20 5 11 17 2 4 8 6 25 15
	Node* root=NULL;
	cout<<"Enter the data for node "<<endl;
	takeInput(root);
	levelOrderTraversal(root);
	cout<<search(root,18);
	root = deleteNodeInBST(root,150);
	levelOrderTraversal(root);
	return 0;
}
