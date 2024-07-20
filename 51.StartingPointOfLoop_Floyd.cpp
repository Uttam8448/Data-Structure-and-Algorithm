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

//checking loop using loop(Floyd Detection)
Node* checkforloop(Node* &head){
	if(head == NULL){
		cout<< "LL is empty!!\n";
		return NULL;
	}
	Node* slow = head;
	Node* fast = head;
	
	while(fast != NULL){
		fast = fast -> next;
		if(fast != NULL){
			fast = fast -> next;
			slow = slow -> next;
		}
		if(slow == fast){
			return fast;
		}
	}
	return NULL;
}


//Floyd Cycle Detection
bool FloydDetection(Node* &slow,Node* &fast){
	if(fast==NULL){
		return false;
	}
	if(slow==fast){
		return true;
	}
	slow=slow->next;
	if(fast->next!=NULL){
		FloydDetection(slow->next,fast->next->next);
	}	
}

Node* StartingPointOfLoop(Node* &head){
	Node* fast=checkforloop(head);
	if(fast==NULL){
		cout<<"LinkedList is empty!!\n";
		return NULL;
	}
	Node* slow = head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	return fast;
}

int main(){
	//Creating nodes
	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third= new Node(30);
	Node* fourth = new Node(40);
	Node* fifth= new Node(50);
	Node* sixth= new Node(60);
	Node* seventh= new Node(70);
	Node* eight= new Node(80);
	Node* ninth= new Node(90);
//Linking nodes
	first->next=second;
	second->next=third;
	third->next=fourth;
	fourth->next=fifth;
	fifth->next=sixth;
	sixth->next=seventh;
	seventh->next=eight;
	eight->next=ninth;
	ninth->next=first;
	//printing nodes or linked list
	cout<<"Starting Point Of Loop:-"<<StartingPointOfLoop(first)->data<<endl;
	return 0;
}

