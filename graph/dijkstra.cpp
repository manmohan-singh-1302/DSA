#include<bits/stdc++.h>
int n,m,s;
const int INF = 1000000000;
vector<vector<pair<int,int>>> adj;
vector<int> d;
vector<int> p;
using namespace std;
void dijkstra(){
    d.assign(n,INF);
    p.assign(n,-1);
    vector<bool> u(n,false);
    d[s]=0;
    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++){
            if(!u[j]&&(v==-1||d[j]<d[v]))
                v=j;
        }
        if(d[v]==INF)
        break;
        u[v]=true;
        for(auto edge: adj[v]){
            int to = edge.first;
            int len = edge.second;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                p[to]=v;
            }

        }
    }
}
int main(){
    cin>>n>>m;
    cin>>s;
    adj.resize(n);
    for(int i=0;i<n;i++){
    adj[i].resize(m);
}
int a,b,w;
for(int i=0;i<m;i++){
    adj[a].push_back(make_pair(b,w));
    adj[b].push_back(make_pair(a,w));
}

dijkstra();
        }