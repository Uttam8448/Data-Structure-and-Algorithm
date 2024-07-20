#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			this->data=0;
			this->next=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};

Node* reverse(Node* &head){
	Node* prev = NULL;
	Node* curr = head;
	Node* temp = curr->next;
	while(curr!=NULL){
		temp = curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	return prev;
}

Node* solve1(Node* &head1,Node* &head2){
	void print(Node* &head);
	//step1 : reverse both linked list
	head1=reverse(head1);
	head2=reverse(head2);
	
	//step2 : add both linked list
	Node* ansHead=NULL;
	Node* ansTail=NULL;
	int carry=0;
	while(head1!=NULL && head2!=NULL){
		int sum = carry + head1 -> data + head2 ->data;
		int digit = sum%10;
		carry = sum/10;
		
		Node* newNode = new Node(digit);
		if(ansHead == NULL) {
			ansHead = newNode;
			ansTail = newNode;
		}
		else{
			ansTail ->next=newNode;
			ansTail = newNode;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	//remaining head1
	while(head1 != NULL){
		int sum = carry + head1 -> data;
		int digit = sum%10;
		carry = sum / 10;
		Node* newNode = new Node(digit);
		ansTail -> next=newNode;
		ansTail = newNode;
		head1 = head1 -> next;
	}

	//remaining head2
	while(head2 != NULL){
		int sum = carry + head2 -> data;
		int digit = sum % 10;
		carry = sum / 10;
		Node* newNode = new Node(digit);
		ansTail -> next=newNode;
		ansTail = newNode;
		head2 = head2 -> next;
	}
	while(carry != 0){
		int sum = carry;
		int digit = sum % 10;
		carry = sum /10;
		Node* newNode = new Node(digit);
		ansTail ->next=newNode;
		ansTail = newNode;
	}
	//step3 : reverse the ans linked list
	ansHead=reverse(ansHead);
	return ansHead;
}
void print(Node* &head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
//	Node* head1 =new Node(2);
//	Node* second1 =new Node(4);
//	head1->next = second1;
//	Node* head2 = new Node(2);
//	Node* second2 = new Node(3);
//	Node* third2 = new Node(4);
//	head2->next = second2;
//	second2->next = third2;

	Node* head1 =new Node(9);
	Node* second1 =new Node(9);
	head1->next = second1;
	Node* head2 = new Node(9);
	Node* second2 = new Node(9);
	head2->next = second2;
	Node* sum=solve1(head1,head2);
	print(sum);
	return 0;
	
}
