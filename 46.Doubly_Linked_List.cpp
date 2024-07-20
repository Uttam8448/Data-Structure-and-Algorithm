#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	Node(){
		this->data =  0;
		this->next = NULL;
		this->prev = NULL;
	}
	Node(int data){
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
	~Node(){
		cout<<"Deleting Node with data:- "<<this->data<<"\n";
	}
	
};
//Time Complexity-O(n)
int getLength(Node* head){			//pass by value
	int len = 0;
	Node* temp = head;
	
	while(temp != NULL){
		len++;
		temp=temp->next;
	}
	return len; 
}
//Time Complexity-O(n)
void print(Node* &head){
	Node* temp = head;
	cout<<"Printing the Linked list : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

void InsertAtHead(Node* &head,Node* &tail, int data){
	if(head == NULL){
		Node* newNode = new Node(data);
		head = newNode;
		tail = newNode;
	}
	else{
		Node* newNode= new Node(data);
		head->prev = newNode;
		newNode->next= head;
		head = newNode;
	}
}

void InsertAtTail(Node* &head,Node* &tail,int data){
	if(head == NULL){
		Node* newNode = new Node(data);
		head= newNode;
		tail = newNode;
	}
	else{
		Node* newNode = new Node(data);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void InsertAtPosition(Node* &head,Node* &tail,int position,int data){
	if(head == NULL){
		Node* newNode = new Node(data);
		head= newNode;
		tail = newNode;
	}
	else{
		if(position == 1){
			InsertAtHead(head,tail,data);
			return;
		}
		int length = getLength(head);
		if(length < position){
			InsertAtTail(head,tail,data);
			return;
		}
		Node* prevNode=head;
		int i=1;
		while(i<position-1){
			prevNode=prevNode->next;
			i++;
		}
		Node* currNode = prevNode->next;
		Node* newNode = new Node(data);
		prevNode->next=newNode;
		currNode->prev = newNode;
		newNode->prev = prevNode;
		newNode->next = currNode;
		
	}	 
}

void DeleteFromPosition(Node* &head,Node* &tail,int position) {
	if(head==NULL){
		cout<<"Linked List is Empty!! \n";
		return;
	}
	if(head->next==NULL){
		//single node
		Node* temp = head;
		head = NULL;
		tail = NULL;
		delete temp;
		return;
	}
	if(position == 1) {
		//want to delete head
		Node* temp = head;
		head = head->next;
		head->prev = NULL;
		temp->next = NULL;
		delete temp;
		return;
	}
	int len = getLength(head);
	if(position > len){
		cout<<"Please Enter a valid position !!\n";
		return;
	}
	if(position==len){
		//delete last node
		 Node* temp = tail;
		 tail = tail->prev;
		 temp->prev = NULL;
		 tail->next = NULL;
		 delete temp;
		 return;
	} 	
	int i=1;
	Node* left=head;
	while(i < position-1){
		left=left->next;
		i++;
	}
	Node* curr=left->next;
	Node* right=curr->next;
	left->next=right;
	right->prev=left;
	curr->prev=NULL;
	curr->next==NULL;
	delete curr;
	return;
}

int main(){
	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);
	Node* head = first;
	Node* tail = third;
	
	first->next = second;
	second->prev = first;
	
	second->next = third;
	third->prev = second;
	print(first);
	
	InsertAtHead(head,tail, 5);
	print(head);
	InsertAtTail(head,tail,40);
	print(head);
	
//	Node* head = NULL;
//	Node* tail = NULL;
//	InsertAtTail(head,tail,40);
//	print(head);

	InsertAtPosition(head,tail,1,6);
	InsertAtPosition(head,tail,7,60);
	InsertAtPosition(head,tail,5,50);
	print(head);
	
	DeleteFromPosition(head,tail,1);
	print(head);
	DeleteFromPosition(head,tail,7);
	print(head);
	DeleteFromPosition(head,tail,3);
	print(head);
	return 0;
}
