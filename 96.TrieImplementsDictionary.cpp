#include<iostream>
#include<vector>
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
void storeSuggestion(TrieNode* curr,vector<string> &temp , string &prefix){
  if(curr->isTerminal){
    temp.push_back(prefix);
  }
  //a to z choices
  for(char ch='a';ch<='z';ch++){
    int index = ch-'a';
    TrieNode* next = curr->children[index];	
    if(next != NULL){
      prefix.push_back(ch);
      storeSuggestion(next, temp, prefix);
      prefix.pop_back();
    }	
  }
}
vector<vector<string> > getSuggestion(TrieNode* root, string input){
  TrieNode* prev = root;
  string prefix="";
  vector<vector<string> > output;
  for(int i=0;i<input.length();i++){
    char lastch = input[i];
    
    int index = lastch - 'a';
    TrieNode* curr = prev->children[index];
    
    if(curr == NULL)
      break;
    else{
      vector<string> temp;
       prefix.push_back(lastch);
      storeSuggestion(curr,temp,prefix);
      output.push_back(temp);
      prev=curr;
    }
  }
  return output;
}

int main() {
  vector<string> v;
  v.push_back("love");
  v.push_back("loving");
  v.push_back("last");
  v.push_back("lost");
  v.push_back("lame");
  v.push_back("lord");
  v.push_back("lover");

  string input = "lovi";
  TrieNode* root=new TrieNode('-');
  for(int i=0;i<v.size();i++){
    insertWord(root,v[i]);
  }
  vector<vector<string> > ans = getSuggestions(root , input);

  cout<< "Printing the answer: "<<endl;
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<",";
    }
    cout<<endl;
  }

}
