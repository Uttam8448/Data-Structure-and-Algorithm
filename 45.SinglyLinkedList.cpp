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

int main(){
	//1.
	//Creating nodes
//	Node* first = new Node(10);
//	Node* second = new Node(20);
//	Node* third= new Node(30);
//	Node* fourth = new Node(40);
//	Node* fifth= new Node(50);
	//Linking nodes
//	first->next=second;
//	second->next=third;
//	third->next=fourth;
//	fourth->next=fifth;
//	//printing nodes or linked list
//	cout<<"Printing the LL : ";
//	print(first);

//2.
//Inserting at head
//	Node* head = new Node(10);
//	Node* second = new Node(20);
//	Node* third= new Node(30);
//	Node* fourth = new Node(40);
//	Node* tail= new Node(50);
//	head->next=second;
//	second->next=third;
//	third->next=fourth;
//	fourth->next=tail;
//	print(head);
//	InsertAtHead(head,5);
//	InsertAtHead(head,4);
//	InsertAtHead(head,3);
//	InsertAtHead(head,2);
//	InsertAtHead(head,1);
//	cout<<"After Insert at head!\n";
//	print(head);
//	InsertAtTail(tail,51);
//	InsertAtTail(tail,52);
//	InsertAtTail(tail,53);
//	InsertAtTail(tail,54);
//	InsertAtTail(tail,55);
//	cout<<"After Insert at tail!\n";
//	print(head);


////3.
//	Node* head = NULL;
//	Node* tail = NULL;
//	InsertAtHead(head,tail,20);
//	InsertAtTail(head,tail,30);		//tail needs to be declared
//	InsertAtHead(head,tail,10);
//	InsertAtTail(head,tail,40);
//	print(head);
//	cout<<endl;
//	InsertAtPosition(1,head,tail,15);
//	InsertAtPosition(2,head,tail,16);
//	InsertAtPosition(3,head,tail,17);
//	cout<<"Middle Insertion !!\n";
//	print(head);
//	cout<<endl;
//	InsertAtPosition(0,head,tail,9);
//	InsertAtPosition(10,head,tail,50);
//	cout<<"End Case Insertion !!\n";
//	print(head);
//4.
	Node* head = NULL;
	Node* tail = NULL;
	InsertAtHead(head,tail,20);
	InsertAtTail(head,tail,30);		//tail needs to be declared
	InsertAtHead(head,tail,10);
	InsertAtTail(head,tail,40);
	print(head);
	cout<<endl;
	DeleteNode(1,head,tail);
	print(head);
	DeleteNode(2,head,tail);
	print(head);
	DeleteNode(2,head,tail);
	print(head);
	return 0;
}
