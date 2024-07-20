//Not Work in dev but works in online compiler
#include<iostream>
#include<vector>
using namespace std;
void printSolution(vector<vector<int>> &board,int n){
  for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl;
}
bool isSafe(int row,int col,vector<vector<int>> &board,int n){
	//check karna chahte hai kya mai current cell par queen rakh sakta hu
	 int i=row;
	 int j=col;
	 //row check
	 for(;j>=0;j--){
	 	if(board[i][j]==1){
	 		return false;
		 }
	 }
	 //check upper left diagonal
  i=row;
  j=col;
  while(i>=0 && j>=0){
    if(board[i][j]==1){
      return false;
    }
    i--;
    j--;
  }
	 //check bottom left diagonal
	i=row;
  j=col;
  while(i<n && j>=0){
    if(board[i][j]==1){
      return false;
    }
    i++;
    j--;
  }
	 return true;
}
void solve(vector<vector<int>> &board,int col,int n ){
	//base case
	if(col>= n){
		printSolution(board,n);
		return;
	} 
	
	//ek case solve karna hai baaki recursion samhal lega
	for(int row =0 ;row<n;row++){
		if(isSafe(row,col,board,n)){
			//rakh do
			board[row][col]=1;
			//recursion solution layega
			solve(board,col+1,n);
			//backtrack
			board[row][col]=0;
		}
	}
}

int main(){
	int n=5;
	vector<vector<int>> board(n,vector<int>(n,0));
	int col=0;
	//0 ka matlab no queen 1 ka matlab hai queen
	solve(board, col,n);
	return 0;
}
