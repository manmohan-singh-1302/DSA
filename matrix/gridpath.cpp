#include<bits/stdc++.h>
using namespace std;
bool ans = false;
vector<vector<int>> g;
void check(int n, vector<vector<int>> &g, int m, int a, int b, queue<pair<int,int>> &q){
    if(a<n && a>=0 && b>=0 && b<m){
        if(g[a][b]==3){
            g[a][b]=1;
            q.push({a,b});
        }
        if(g[a][b]==2){
            ans = true;
            return;
        }
    }
}
void findPath(vector<vector<int>> &g,int n){
    // cout<<"entered"<<endl;
    // int n = g.size();
    // int m = g[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==1)
                q.push({i,j});
        }
    }
    while(!q.empty()){
        // cout<<"loop entered"<<endl;
        int a = q.front().first;
        int b = q.front().second;
        check(n,g,n,a-1,b,q);
        check(n,g,n,a+1,b,q);
        check(n,g,n,a,b-1,q);
        check(n,g,n,a,b+1,q);
        q.pop();
}
// cout<<"done"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        g.resize(n);
        for(int i=0;i<n;i++){
            g[i].resize(n);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>g[i][j];
            }
        }
        findPath(g,n);
    cout<<ans<<endl;
    }
    retur