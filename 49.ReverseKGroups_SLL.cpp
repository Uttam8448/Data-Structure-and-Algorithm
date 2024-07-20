#include<iostream>
using namespace std;
class Node{
	public:int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	~Node() {
		cout<< "Node with value: "<<this->data << " deleted;\n";
	}
};

void InsertAtHead(Node* &head,Node* &tail,int data){
	if(head==NULL){
		Node* newNode = new Node(data);
		head=newNode;
		tail=newNode;
	}	
	else{
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}
}
int getLength(Node* &head){
	Node* temp = head;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}
//I want to insert right at end of ll
void InsertAtTail(Node* &head,Node* &tail,int data){
	if(head==NULL){
		Node* newNode = new Node(data);
		head=newNode;
		tail=newNode;
	}	
	else{
		Node* newNode = new Node(data);
		tail->next = newNode;
		tail = newNode;
	}
}
int FindLength(Node* &head){
	Node* temp = head;
	int count=0;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	return count;
}
//Insert at Position
void InsertAtPosition(int position,Node* &head,Node* &tail,int data){
	if(head==NULL){
		Node* newNode = new Node(data);
		head = newNode;
		tail = newNode;
	}
	if(position==0){
		InsertAtHead(head,tail,data);
		return;
	}
	int length = FindLength(head);
	if(position >= length){
		InsertAtTail(head,tail,data);
		return;
	}
	//step1: find the position prev and curr
	int i=1;
	Node* prev = head;
	while(i < position) {
		prev = prev->next;
		i++;
	}
	Node* curr = prev ->next;
	
	//step2;
	Node* newNode = new Node(data);
	
	//step3
	newNode->next = curr;
	
	//step4;
	prev->next = newNode;
}

//Delete head node
void DeleteHeadNode(Node* &head){
	Node* temp = head;
	head = head->next;
	delete temp;
}
//Deletion of Node
void DeleteNode(int position, Node* &head,Node* &tail){
	if(head == NULL){
		cout<<"Cannot DELETE, it is empty!\n";
		return;
	}
	if(position==1){
			Node* temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
			return;
	}
	int length = FindLength(head);
	//deleting last node
	if(position == length){
		//find prev
		Node* prev=head;
		int i=1; 
		while(i<position-1){
			prev=prev->next;
			i++;
		}
		//prev->next=NULL;
		prev->next=NULL;
		//step3
		Node* temp = tail;
		//step4
		tail=prev;
		//step 5;
		delete temp;
		return;
	}
	int i=1;
	Node* prev = head;
	while(i<position-1){
		prev=prev->next;
		i++;
	}
	Node* curr = prev->next;
	prev->next=curr->next;
	curr->next=NULL;
	delete curr; 
}
//Print
void print(Node* &head){
	 Node* temp=head;
	 cout<<"Printing The LinkedList : ";
	 while(temp!= NULL){
	 	cout<<temp->data<<" ";
	 	temp=temp->next;
	 }
	 cout<<endl;
}
//reverse k nodes
Node* reverseKNodes(Node* &head,int k){
	if(head==NULL){
		//LL reverse ho chuki hai
		cout<<"LL is Empty";
		return head;
	}
	int len = getLength(head);
	if(k>len){
		cout<<"Enter valid value for k!!\n";
		return head;
	}
	//it means number of nodes in LL is >= K
	//Step A - Reverse first k nodes of LL
	Node* prev = NULL;
	Node* curr = head;
	Node* forward = curr -> next;
	int count=0;
	while(count<k){
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
		count++;
	}
	if(forward != NULL){
		//we  still have nodes left to reverse
		head -> next = reverseKNodes(forward, k);
	}
	return prev;	
}
int main(){
	Node* head = NULL;
	Node* tail = NULL;
	InsertAtHead(head,tail,77);
	InsertAtHead(head,tail,20);		//tail needs to be declared
	InsertAtHead(head,tail,50);
	InsertAtHead(head,tail,60);
	InsertAtHead(head,tail,90);	
	InsertAtHead(head,tail,100);
	print(head);	
	head = reverseKNodes(head,7);
	print(head);
	return 0;
}
