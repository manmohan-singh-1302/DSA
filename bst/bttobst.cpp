#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *generate(string s)
{
    if (s.length() == 0 || s[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream is(s);
    for (string s; is >> s;)
        ip.push_back(s);
    node *root = new node(stoi(ip[0]));
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < ip.size())
    {
        node *currNode = q.front();
        q.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
class Solution
{
public:
    void inorderTree(node *root, vector<int> &v)
    {
        if (!root)
            return;
        inorderTree(root->left, v);
        v.push_back(root->data);
        inorderTree(root->right, v);
    }
    void inorderBst(node *root, int &i, vector<int> &v)
    {
        if (!root)
            return;
        inorderBst(root->left, i, v);
        root->data = v[i++];
        inorderBst(root->right, i, v);
    }
    node *btToBst(node *root)
    {
        vector<int> v;
        int i = 0;
        if (!root)
            return NULL;
        inorderTree(root, v);
        sort(v.begin(), v.end());
        inorderBst(root, i, v);
        return root;
    }
};

int main()
{
    string s;
    getline(cin, s);
    node *root = generate(s);
    Solution o;
    node *res = o.btToBst(root);
    inorder(res);
    return 0;
}