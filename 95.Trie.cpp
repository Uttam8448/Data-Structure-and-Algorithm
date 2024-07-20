#include<iostream>
using namespace std;

class TrieNode{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		
		TrieNode(char d){
			this->data=d;
			for(int i=0;i<26;i++){
				children[i]=NULL;
			}
			this->isTerminal = false;
		}
};
void insertWord(TrieNode* root,string word){
	cout<<"Inserting " << word <<endl;
	//base case
	if(word.length()==0){
		root->isTerminal = true;
		return;
	}
	char ch = word[0];
	int index = ch - 'A';
	TrieNode* child;
	//present
	if(root->children[index] != NULL ){
		child = root->children[index];
	}
	else{
		//not present
		child = new TrieNode(ch);
		root->children[index] = child;
	}
	//recursion samhal lega
	insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root,string word){
	if(word.length()==0){
		return root->isTerminal;
	}
	char ch = word[0];
	int index = ch - 'A';
	TrieNode* child;
	//present
	if(root->children[index]!=NULL){
		child = root->children[index];
	}
	else{
		return false;
	}
	return searchWord(child,word.substr(1));
}
int main(){
	TrieNode* root = new TrieNode('-');
	insertWord(root,"CODING");
	insertWord(root,"CODER");
	cout<<searchWord(root,"CODER");
	return 0;
}
//Inserting CODING
//Inserting ODING
//Inserting DING
//Inserting ING
//Inserting NG
//Inserting G
//Inserting

