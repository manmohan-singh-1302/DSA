#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *newnode(int value)
{
    node *n = new node;
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node *insert(node *root, int value, queue<node *> &q)
{
    node *temp = newnode(value);
    if (root == NULL)
        root = temp;
    else if (q.front()->left == NULL)
        q.front()->left = temp;
    else
    {
        q.front()->right = temp;
        q.pop();
    }
    q.push(temp);
    return root;
}
node *tree(int arr[], int n)
{
    node *head = NULL;
    queue<node *> q;
    for (int i = 0; i < n; i++)
        head = insert(head, arr[i], q);
    return head;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void right(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *x = q.front();
            q.pop();
            if (n == 0)
                cout << x->data << " ";
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    node *root = tree(arr, n);
    inorder(root);
    cout << endl;
    // rightView(root);
    right(root);
}