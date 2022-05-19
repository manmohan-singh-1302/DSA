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
        left = right = NULL;
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
class Solution
{
public:
    void util(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        util(root->left, ans);
        ans.push_back(root->data);
        util(root->right, ans);
    }
    int KthSmallestElement(Node *root, int K)
    {
        // add code here.
        vector<int> ans;
        util(root, ans);
        if (K <= ans.size())
            return ans[K - 1];
        return -1;
    }
};
int main()
{
    string s;
    getline(cin, s);
    node *root = generate(s);
    int k;
    cin >> k;
    Solution o;
    int ans = o.kthlargest(root, k);
    cout << ans;
}

/*
class Solution
{
    public:
  void kthLargestUtil(Node *root, int k, int &c, int &res)
    {
        if (root == NULL || c >= k)
            return;

        kthLargestUtil(root->right, k, c, res);

        c++;
        if (c == k)
        {
            res = root->data;
            return;
        }

        kthLargestUtil(root->left, k, c, res);
    }

    public:
    int kthLargest(Node *root, int k)
    {
        int c = 0;
        int res = -1;
        kthLargestUtil(root, k, c, res);
        return res;
    }
};
*/