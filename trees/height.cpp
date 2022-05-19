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
void postorder(node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
void levelorder(node* root){
	//preorder
	if(root == NULL)
		return;
	queue<node*> n;
	n.push(root);
	while(!n.empty()){
		cout<<n.front()->data<<" ";
		if(n.front()->left != NULL)
			n.push(n.front()->left);
		if(n.front()->right != NULL)
			n.push(n.front()->right);
		n.pop();
	}
    cout<<endl;
}
    int height(node* node){
        if (node == NULL)  // base case
        return 0;
        
    int maxLeftHeight = height(node->left);
    int maxRightHeight = height(node->right);
    
    if(maxLeftHeight>maxRightHeight)
        return maxLeftHeight+1;
    return maxRightHeight+1;
    
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	node* root = tree(a,n);
	levelorder(root);
    cout<<endl;
    inorder(root);
	cout<<endl;
	cout<<"the postorder is:"<<endl;
	postorder(root);
    cout<<endl;
    cout<<"the height of the tree is:"<<height(root);
	return 0;
}
/* iterative approach
int height(struct Node* root){
    if (root == NULL)
        return 0;
        
    queue<Node*> q;
    
    q.push(root);
    int counter = 0;
    while (!q.empty()) {
        int queueSize = q.size();
        
        for (int i=0; i<queueSize; i++) {
            Node* curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        
        counter++;
    }
    
    return counter;
}*/