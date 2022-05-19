#include <bits/stdc++.h>
using namespace std;
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
node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}
int main()
{
    string s;
    getline(cin, s);
    node *root = generate(s);
    int key;
    cin >> key;
    if (search(root, key))
        cout << "element found";
    else
        cout << "element not found";
}