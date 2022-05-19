#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* newnode(int value){
	node* n = new node;
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}
node* insert(node* root, int value, queue<node*>& q){
	node* temp = newnode(value);
	if(root == NULL)
		root = temp;
	else if(q.front()->left == NULL)
		q.front()->left = temp;
	else{
		q.front()->right = temp;
		q.pop();
	}
	q.push(temp);
	return root;
}
node* tree(int a[], int n){
	node* head = NULL;
	queue<node*> q;
	for(int i=0;i<n;i++)
		head = insert(head,a[i],q);
	return head;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node* mirror(node* root){
	if(root == NULL)
		return root;
	node* t = root->left;
	root->left = root->right;
	root->right = t;
	if(root->right)
		mirror(root->right);
	if(root->left)
		mirror(root->left);
	return root;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	node* root = tree(a,n);
	cout<<"the inorder traversal is:";
    inorder(root);
	mirror(root);
	cout<<endl;
	cout<<"inorder of mirror tree is:"<<endl;
	inorder(root);
	return 0;
}