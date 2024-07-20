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
node* buildTree(){
		cout<<"Enter the data: " <<endl;
		int data;
		cin>>data;
		if(data==-1){
			return NULL;
		}
		//step1:Create Node
		node* root = new node(data);
		//step2:Create left Subtree
		root->left = buildTree();
		///step3:Create right Subtree
		root->right = buildTree();
		return root;
	}
//void levelOrderTraversal(node* root){
//	queue<node* > q;
//	q.push(root);
//	while(!q.empty()){
//		node* temp=q.front();
//		cout<<temp->data <<" ";
//		q.pop();
//		
//		if(temp->left){
//			q.push(temp->left);
//		}
//		if(temp->right){
//			q.push(temp->right);
//		}
//	}
///*1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//Enter data for inserting in left 1
//Enter the data:
//Enter data for inserting in left 3
//Enter the data:
//Enter data for inserting in left 7
//Enter the data:
//Enter data for inserting in right of 7
//Enter the data:
//Enter data for inserting in right of 3
//Enter the data:
//Enter data for inserting in left 11
//Enter the data:
//Enter data for inserting in right of 11
//Enter the data:
//Enter data for inserting in right of 1
//Enter the data:
//Enter data for inserting in left 5
//Enter the data:
//Enter data for inserting in left 17
//Enter the data:
//Enter data for inserting in right of 17
//Enter the data:
//Enter data for inserting in right of 5
//Enter the data:
//Level Order Traversal(Breadth first search) :
//1 3 5 7 11 17
//--------------------------------
//Process exited after 31.03 seconds with return value 0
//Press any key to continue . . .*/
//}
void levelOrderTraversal(node* root){
	queue<node* > q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
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
//Enter the data:
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//Enter data for inserting in left 1
//Enter the data:
//Enter data for inserting in left 3
//Enter the data:
//Enter data for inserting in left 7
//Enter the data:
//Enter data for inserting in right of 7
//Enter the data:
//Enter data for inserting in right of 3
//Enter the data:
//Enter data for inserting in left 11
//Enter the data:
//Enter data for inserting in right of 11
//Enter the data:
//Enter data for inserting in right of 1
//Enter the data:
//Enter data for inserting in left 5
//Enter the data:
//Enter data for inserting in left 17
//Enter the data:
//Enter data for inserting in right of 17
//Enter the data:
//Enter data for inserting in right of 5
//Enter the data:
//Level Order Traversal(Breadth first search) :
//1
//3 5
//7 11 17
//
//--------------------------------
//Process exited after 23.73 seconds with return value 0
//Press any key to continue . . .

void preorderTraversalR(node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorderTraversalR(root->left);
	preorderTraversalR(root->right);
}



void inorderTraversalR(node* root){
	if(root==NULL)
		return;
	inorderTraversalR(root->left);
	cout<<root->data<<" ";
	inorderTraversalR(root->right);
}
void inorderTraversal(node* root){
        if(root==NULL)
        return;
        stack<node*> s;
        s.push(root);
	 	while(!s.empty()){
            if(s.top()->left){
            	s.push(s.top()->left);
			}                 
            else{
                node* temp=s.top();
                s.pop();
                cout<<(temp->data);
                if(temp->right)
                    s.push(temp->right);
            }
        }
}



void postorderTraversalR(node* root){
	if(root==NULL)
		return;
	postorderTraversalR(root->left);
	postorderTraversalR(root->right);
	cout<<root->data<<" ";
}

//Enter the data:
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Enter the data:
//Level Order Traversal(Breadth first search) :
//1
//3 5
//7 11 17
//
//Pre-Order Traversal:
//1 3 7 11 5 17
//In-Order Traversal:
//7 3 11 1 17 5
//Post-Order Traversal:
//7 11 3 17 5 1

int main(){
	node* root= NULL;
	
	//creating a tree
	root=buildTree();
	
	//level order
	cout<<"Level Order Traversal(Breadth first search) :\n";
	levelOrderTraversal(root);
	
	cout<<"\nPre-Order Traversal:\n";
	preorderTraversalR(root);
	
	cout<<"\nIn-Order Traversal:\n";
	inorderTraversalR(root);
	
	cout<<"\nPost-Order Traversal:\n";
	postorderTraversalR(root);
	

	return 0;
}

