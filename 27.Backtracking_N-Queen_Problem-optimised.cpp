//Not Work in dev but works in online compiler
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;
void printSolution(vector<vector<int>> &board,int n){
  for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl;
}
bool isSafe(int row,int col,int n){
    if(rowCheck[row]==true){
      return false;
    }
    if(upperLeftDiagonalCheck[n-1+col-row]==true){
      return false;
    }
    if(bottomLeftDiagonalCheck[col+row]==true){
      return false;
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
		if(isSafe(row,col,n)){
			//rakh do
			board[row][col]=1;
			//recursion solution layega
      rowCheck[row]=true;
      upperLeftDiagonalCheck[n-1+col-row]=true;
      bottomLeftDiagonalCheck[col+row]=true;
	    solve(board,col+1,n);
		//backtrack
		board[row][col]=0;
      rowCheck[row]=false;
      upperLeftDiagonalCheck[n-1+col-row]=false;
      bottomLeftDiagonalCheck[col+row]=false;
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

