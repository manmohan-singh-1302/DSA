#include<bits/stdc++.h>
using namespace std;
void add(vector<int> a[], int u, int v){
  a[u].push_back(v);
  a[v].push_back(u);
}
void printGraph(vector<int> a[], int v){
  for(int i=0;i<v;i++){
    cout<<"adjaceny list of vertex"<<i<<"head";
    for(auto x:a[i])
      cout<<"->"<<x;
    cout<<endl;
  }
}
int main(){
  int v= 5;
  vector<int> a[v];
  add(a,0,1);
  add(a,0,4);
  add(a,1,2);
  add(a,1,3);
  add(a,1,4);
  add(a,2,3);
  add(a,3,4);
  printGraph(a,v);
  // dfs(a,v);
  return 0;
}

//bfs implementation using stl in cpp
/*#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<bool> v;//visited
vector<vector<int>> g;//graph
void edge(int a, int b){
  g[a].pb(b);
}
void bfs(int s){
  queue<int> q;
  q.push(s);
  v[s]=true;
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    cout<<temp<<" ";
    for(auto i=g[temp].begin();i!=g[temp].end();i++){
      if(!v[*i]){
        q.push(*i);
        v[*i] = true;
      }
    }
  }
}
int main(){
  int n,e;
  cin>>n>>e;
v.assign(n,false);
g.assign(n,vector<int>());
int a,b;
for(int i=0;i<e;i++){
  cin>>a>>b;
  edge(a,b);
}
for(int i=0;i<n;i++){
  if(!v[i])
    bfs(i);
}
  return 0;
}*/