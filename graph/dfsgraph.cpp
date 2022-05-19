#include<bits/stdc++.h>
using namespace std;
void check(int s, vector<int> adj[], int v, vector<bool> &vis, vector<int> &res){
    if(vis[s])
    return ;
    vis[s] = true;
    res.push_back(s);
    for(auto i:adj[s]){
        if(!vis[i]){
            check(i,adj,v,vis,res);
        }
    }
}
vector<int> dfs(int v, vector<int> adj[]){ 
    vector<int> res;//for storing the result i.e. the dfs of the graph
    vector<bool> vis(v,false);//for marking all the vertices as not visited
    for(int i=0;i<v;i++){
        if(!vis[i]){
            check(i,adj,v,vis,res);
        }
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<int> adj[v];
        int a,b;
        for(int i=0;i<e;i++){
            cin>>a>>b;
            adj[a].push_back(b);
        }
        vector<int> ans = dfs(v,adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}