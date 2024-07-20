#include<iostream>
using namespace std;
int main(){
	//Adjacency matrix way to store or implement graph in cpp
	//Space Complexity==>O(N*N)
//	int n;int m;
//	cin>>n>>m;
//	int adj[n+1][n+1];
//	for(int i=0;i<m;i++){

//		edge input
//		int u,v;
//		cin>>u>>v;
//		adj[u][v]=1;
//		adj[v][u]=1;
//		
//	}

	//Adjacency list way to store or implement graph in cpp
	//Space Complexity==>O(2E)...E=m
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	return 0;
}
