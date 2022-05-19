#include<iostream>
#include<queue>
using namespace std;
void show(queue<int> q){
    queue<int> g = q;
    while(!g.empty()){
        cout<<g.front()<<" ";
        g.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    show(q);
    cout<<q.front()<<endl;
    cout<<q.back();
}