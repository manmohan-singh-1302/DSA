#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
void hashandremove(node* head){
    unordered_map<node*, int> u;
    node* last = NULL;
    while(head!=NULL){
        if(u.find(head)==u.end()){
            u[head]++;
            last = head;
            head = head->next;
        }
        else{
            last->next = NULL;
            break;
        }
    }
    cout<<endl;
}
void insert(node** head_ref, int key){
    node* temp = new node;
    temp->data = key;
    temp->next = *head_ref;
    *head_ref = temp;
}
node* arrayTo(int a[], int n){
    node* head = NULL;
    for(int i=n-1;i>=0;i--)
        insert(&head,a[i]);
    return head;
}
void display(node* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    node* root = arrayTo(a,n);
    display(root);
    hashandremove(root);
    display(root);
}