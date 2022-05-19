#include<bits/stdc++.h>
using namespace std;
#define push_back pb
void color(vector<int> adj, int n){
    int result[v];
    result[0] = 0;//assingning the first colour to the first vertex of the graph
    for(int i=0;i<n;i++){
        result[i] = -1;//initialising remaining vertices as unassigned
    }
    //create a temp array to store all the available colours 
    bool ava[n];
    for(int 0;i<n;i++){
        ava[i]=false;
    }
    //assigning colours to the remaining vertices of the graph
    for(int i=1;i<n;i++){
        vector<int>:: iterator itr;
        for(i=adj[i].begin();i!+adj[i].end();i++)
            
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    return 0;
}