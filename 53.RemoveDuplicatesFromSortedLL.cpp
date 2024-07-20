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
//More_Optimised
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

void RemoveDuplicates(Node* &head){
	if(head==NULL){
		cout<<"Empty LL!!\n";
		return;
	}
	if(head->next==NULL){
		cout<<"Single Node in LL!!\n";
		return;
	}
	Node* curr=head;
	while(curr!=NULL){
		if(curr->next!=NULL && curr->data==curr->next->data){
				Node* temp=curr->next;
				curr->next=curr->next->next;
				temp->next=NULL:	//Good practice
				delete tSSSSSemp;
		}
		else{
			curr=curr->next;
		}
	}
	return;
}

int main(){
	//Creating nodes
	Node* head = new Node(10);
	Node* second = new Node(10);
	Node* third= new Node(30);
	Node* fourth = new Node(30);
	Node* fifth= new Node(30);
	//Linking nodes
	head->next=second;
	second->next=third;
	third->next=fourth;
	fourth->next=fifth;
	fifth->next=NULL;
	//printing nodes or linked list
	RemoveDuplicates(head);
	print(head);
	return 0;
}
