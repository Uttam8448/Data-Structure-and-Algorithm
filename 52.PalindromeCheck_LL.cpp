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
////I want to insert a node at the head
//void InsertAtHead(Node* &head,int data){
//	Node* newNode = new Node(data);
//	//step2
//	newNode->next=head;
//	//step3
//	head=newNode;
//}
////I want to insert right at end of ll
//void InsertAtTail(Node* &tail,int data){
//	Node* newNode = new Node(data);
//	//step2
//	tail->next=newNode;
//	//step3
//	tail=newNode;
//}

////Optimised
////I want to insert a node at the head
//void InsertAtHead(Node* &head,Node* &tail,int data){
//	Node* newNode = new Node(data);
//	//step2
//	newNode->next=head;
//	//For First Node
//	if(head==NULL){
//		tail=newNode;
//	}
//	//step3
//	head=newNode;
//}
////I want to insert right at end of ll
//void InsertAtTail(Node* &head,Node* &tail,int data){
//	Node* newNode = new Node(data);
//	//step2
////  tail->next=newNode;			//for 1st element null->next  nothing therefore using if else
//	//for first node
//	if(tail==NULL){
//		head=newNode;
//	}
//	//else case
//	else{
//		tail->next=newNode;			
//	}
//	//step3
//	tail=newNode;
//}
//


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

bool CheckPallindrome(Node* &head){
	if(head==NULL){
		cout<<"LL is empty!!" << endl;
		return true;
	}
	if(head->next == NULL ){
		return true;
	}
	//step A:Finding midd
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	print(head);
	Node* prev=NULL;
	Node* curr=slow->next;
	Node* nextNode = curr->next;
	while(curr!=NULL){
		nextNode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextNode;
	} 
	slow->next=prev;
	print(head);
	Node* check1=head;
	Node* check2=prev;
	while(check2!=NULL){
		if(check1->data!=check2->data || check2==slow){
			return false;
		}
		check1=check1->next;
		check2=check2->next;
	}
	return true;
}
int main(){
	//Creating nodes
	Node* head = new Node(10);
	Node* second = new Node(20);
	Node* third= new Node(30);
//	Node* third1= new Node(30);
	Node* fourth = new Node(20);
	Node* fifth= new Node(10);
	//Linking nodes
	head->next=second;
	second->next=third;
	third->next=fourth;
//	third1->next=fourth;
	fourth->next=fifth;
	fifth->next=NULL;
	//printing nodes or linked list
	cout<<CheckPallindrome(head);
//	cout<<"Printing the LL : ";
//	print(head);
	return 0;
}
