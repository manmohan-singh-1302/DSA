#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>> &v, vector<vector<int>> &b, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=v[j][i];
        }
    }
    /* inorder to transpose a matrix and store it in the same matrix use
    void transpose(vector<vector<int>> v, int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j,n;j++){
                swap(v[i][j],v[j][i]);
            }
        }
    }
    */
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    v.resize(n);
    for(int i=0;i<n;i++){
        v[i].resize(n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>v[i][j];
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    vector<vector<int>> b;
    b.resize(n);
    for(int i=0;i<n;i++){
        b[i].resize(n);
    }
    transpose(v,b,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cout<<b[i][j];
    }
    cout<<endl;
    }
    return 0;
}