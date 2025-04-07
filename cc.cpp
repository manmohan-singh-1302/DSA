#include<bits/stdc++.h>
using namespace std;
void bfs()
int main(){
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	return 0;
}