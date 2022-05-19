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
    if (s.size() == 0 || s[0] == 'N')
    {
        return NULL;
    }
    vector<string> ip;
    istringstream is(s);
    for (string s; is >> s;)
    {
        ip.push_back(s);
    }
    node *root = new node(stoi(ip[0]));
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < ip.size())
    {
        node *currnode = q.front();
        q.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currnode->left = new node(stoi(currVal));
            q.push(currnode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currnode->right = new node(stoi(currVal));
            q.push(currnode->right);
        }
        i++;
    }
    return root;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}
class Solution
{
public:
    vector<int> topView(node *root)
    {
        vector<int> ans;

        // base case
        if (root == NULL)
        {
            return ans;
        }

        node *temp = NULL;
        // creating empty queue for level order traversal.
        queue<pair<node *, int>> q;
        // creating a map to store nodes at a particular horizontal distance.
        map<int, int> mp;

        q.push({root, 0});
        while (!q.empty())
        {

            temp = q.front().first;
            int d = q.front().second;
            q.pop();

            // storing temp->data in map.
            if (mp.find(d) == mp.end())
            {
                mp[d] = temp->data;
            }

            // if left child of temp exists, pushing it in
            // the queue with the horizontal distance.
            if (temp->left)
            {
                q.push({temp->left, d - 1});
            }
            // if right child of temp exists, pushing it in
            // the queue with the horizontal distance.
            if (temp->right)
            {
                q.push({temp->right, d + 1});
            }
        }
        // traversing the map and storing the nodes in list
        // at every horizontal distance.
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        // returning the output list.
        return ans;
        return ans;
    }
};

int main()
{
    string tree;
    getline(cin, tree);
    node *root = generate(tree);
    inorder(root);
    cout << endl;
    Solution ob;
    vector<int> vec = ob.topView(root);
    for (int x : vec)
    {
        cout << x << " ";
    }
    return 0;
}