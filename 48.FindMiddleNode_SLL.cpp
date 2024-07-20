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


//Find Midd in basic approach
Node* FindMidd(Node* &head) {
	if(head == NULL) {
		cout<<"LL is empty!!\n";
		return head;
	}
	if(head->next==NULL) {
		return head;
	}
	int count=0;
	Node* temp=head;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	count=count/2;
	temp=head;
	while(count!=0){
		temp=temp->next;
		count--;
	}
	return temp;
}



//Find Midd in 1 scan
Node* FindMid(Node* &head){
	if(head == NULL){
		cout<<"LL is empty!!\n";
		return head;	
	}
	if(head->next==NULL){
		//Only 1 node
		return head;
	}
	//more than 1 node
	Node* slow = head;
	Node* fast = head->next;			//if even ans is n/2
	//for even ans n/2+1 use fast= head
	while(slow!= NULL && fast != NULL) {
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
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
	cout<<FindMidd(head)->data;
	return 0;
}
	
	
	
