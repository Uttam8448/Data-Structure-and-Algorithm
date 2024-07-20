#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			this->data=NULL;
			this->next=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=next;
		}
};

Node* reverse(Node* &head){
	if(head == NULL){
		cout<<"LL is Empty!!/n";
		return NULL;
	}
	if(head->next==NULL){
		return head;
	}
	Node* curr=head;
	Node* prev=NULL;
	Node* temp= curr->next;
	while(curr!=NULL){
		temp = curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	return prev;
}
Node* solve(Node* &head1,Node* &head2){
	//step1 : reverse both linked list
	head1=reverse(head1);
	head2=reverse(head2);
	Node* temp1=head1;
	Node* temp2=head2;
	//step2 : add both linked list
	Node* ans=new Node();
	Node* headOfans=ans;
	while(temp1!=NULL || temp2!=NULL){
		int carry=0;
		if(carry==0){
			int sum=temp1->data + temp2->data;
			if(sum>9){
				carry=1;
				sum=sum%10;
			}
			Node* ansHelper = new Node(sum);
			ans->next =ansHelper;
			ans=ansHelper;
		}
		else{
			int sum=temp1->data + temp2->data + 1;
			if(sum>9){
				carry=1;
				sum=sum%10;
			}
			Node* ansHelper = new Node(sum);
			ans->next= ansHelper;
			ans=ansHelper;
			
		}
	}
	
	//step3 : reverse the ans linked list
	headOfans=reverse(headOfans);
	return headOfans;
}
void print(Node* &head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
	}
	cout<<endl;
}
int main(){
	Node* head1 = new Node(2);
	Node* second1 = new Node(4);
	head1->next=second1;
	Node* head2 = new Node(30);
	Node* second2 = new Node(40);
	Node* third2 = new Node(50);
	head2->next = second2;
	second2->next = third2;
	Node* sum=solve(head1,head2);
	print(sum);
	return 0;
	
}
