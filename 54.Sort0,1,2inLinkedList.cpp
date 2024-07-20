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

void printAddress(Node* &head){
	 Node* temp=head;
	 cout<<"Printing The LinkedList Addresses: ";
	 while(temp!= NULL){
	 	cout<<temp<<" ";
	 	temp=temp->next;
	 }
	 cout<<endl;
}

//Using Counting and Replacement Of Data
void SortZeroOneTwo(Node* &head){
	if(head==NULL){
		cout<<"No LL!!!\n";
		return;
	}
	if(head->next==NULL){
		cout<<"Already Sorted!!\n";
		return;
	}
	Node* temp=head;
	int countZero,countOne,countTwo=0;
	while(temp!=NULL){
		if(temp->data==0){
			countZero++;
			temp=temp->next;
		}
		else if(temp->data==1){
			countOne++;
			temp=temp->next;
		}
		else{
			countTwo++;
			temp=temp->next;
		}
	}
	temp=head;
	while(countZero!=0){
		temp->data=0;
		temp=temp->next;
		countZero--;
	}
	while(countOne!=0){
		temp->data=1;
		temp=temp->next;
		countOne--;
	}
	while(countTwo!=0){
		temp->data=2;
		temp=temp->next;
		countTwo--;
	}
}

//Using Three different Nodes for 0 1 2 and attach them 0 1 2 without replacement
Node* Sort012(Node* &head){
	if(head==NULL){
		cout<<"No LL!!!\n";
		return NULL;
	}
	if(head->next==NULL){
		cout<<"Already Sorted!!\n";
		return NULL;
	}
	Node* Zero=new Node(-1);
	Node* tail0=Zero;
	Node* One=new Node(-1);
	Node* tail1=One;
	Node* Two=new Node(-1);
	Node* tail2=Two;
	Node* temp=head;
	while(temp!=NULL){
		if(temp->data==0){
			InsertAtTail(Zero,tail0,0);
		}
		if(temp->data==1){
			InsertAtTail(One,tail1,1);
		}
		if(temp->data==2){
			InsertAtTail(Two,tail2,2);
		}
		temp=temp->next;
	}
	Zero=Zero->next;
	One=One->next;
	Two=Two->next;
	tail0->next=One;
	tail1->next=Two;
	print(Zero);
	return Zero;
}

//not final
Node* Sort02(Node* &head){
	if(head==NULL){
		cout<<"No LL!!!\n";
		return NULL;
	}
	if(head->next==NULL){
		cout<<"Already Sorted!!\n";
		return NULL;
	}
	Node* Zero=new Node(-1);
	Node* tail0=Zero;
	Node* One=new Node(-1);
	Node* tail1=One;
	Node* Two=new Node(-1);
	Node* tail2=Two;
	Node* curr=head;
	while(curr!=NULL){
		if(curr->data==0){
			//take out the zero node
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail0->next=temp;
			tail0=tail0->next;
		}
		else if(curr->data==1){
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail1->next=temp;
			tail1=tail1->next;
		}
		else if(curr->data==2){
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail2->next=temp;
			tail2=tail2->next;
		}
	}
	Node* Dummy0=Zero;
	Zero=Zero->next;
	Dummy0->next=NULL;
	delete Dummy0;
	Node* Dummy1=One;
	One=One->next;
	Dummy1->next=NULL;
	delete Dummy1;
	Node* Dummy2=Two;
	Two=Two->next;
	Dummy2->next=NULL;
	delete Dummy2;	
	if(tail1!=NULL){
		tail0->next=One;
		if(tail2!=NULL){
			tail1->next=Two;
		}
	}
	else{
		if(tail2!=NULL){
			tail0->next=Two;
		}
	}
	return Zero;
}

//final
Node* Sort021(Node* &head){
	if(head==NULL){
		cout<<"No LL!!!\n";
		return NULL;
	}
	if(head->next==NULL){
		cout<<"Already Sorted!!\n";
		return NULL;
	}
	Node* Zero=new Node(-1);
	Node* tail0=Zero;
	Node* One=new Node(-1);
	Node* tail1=One;
	Node* Two=new Node(-1);
	Node* tail2=Two;
	Node* curr=head;
	while(curr!=NULL){
		if(curr->data==0){
			//take out the zero node
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail0->next=temp;
			tail0=tail0->next;
		}
		else if(curr->data==1){
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail1->next=temp;
			tail1=tail1->next;
		}
		else if(curr->data==2){
			Node* temp=curr;	//seperate 0 node
			curr = curr->next;
			temp->next=NULL;
			
			//append the zero node in zerohead
			tail2->next=temp;
			tail2=tail2->next;
		}
	}
	Node* Dummy1=One;
	One=One->next;
	Dummy1->next=NULL;
	delete Dummy1;
	Node* Dummy2=Two;
	Two=Two->next;
	Dummy2->next=NULL;
	delete Dummy2;	
	
	if(Zero!=NULL){						//tail cant be used as above we had delete
		tail0->next=One;
		if(Two!=NULL){
			tail1->next=Two;
		}
	}
	else{
		if(Two!=NULL){
			tail0->next=Two;
		}
	}
	Node* Dummy0=Zero;
	Zero=Zero->next;
	Dummy0->next=NULL;
	delete Dummy0;
	print(Zero);
	return Zero;
}
int main(){
	//Creating nodes
	Node* head = new Node(1);
	Node* second = new Node(0);
	Node* third= new Node(2);
	Node* fourth = new Node(0);
	Node* fifth= new Node(1);
	Node* sixth= new Node(2);
	//Linking nodes
	head->next=second;
	second->next=third;
	third->next=fourth;
	fourth->next=fifth;
	fifth->next=sixth;
	//printing nodes or linked list
	cout<<"Before Sorting:\n";
	print(head);
	printAddress(head);
	cout<<"After Sorting:\n";
	Node* temp2=Sort021(head);
	print(temp2);
	printAddress(temp2);
	return 0;
}
