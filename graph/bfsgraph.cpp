#include <bits/stdc++.h>
using namespace std;
// class Solution{
//     public:
vector<int> bfs(int v, vector<int> adj[])
{
    // create a boolean array to mark all the vertices as not visited
    vector<bool> vis(v, false);
    int s = 0;
    // mark the first vertex as visited
    vis[s] = true;
    vector<int> res;
    // create a queue for bfs for pushing the first vertex in queue
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        // add the front ele from the queue to res and pop it
        int temp = q.front();
        res.push_back(temp);
        q.pop();
        // travesing over all the front elements
        for (int e : adj[temp])
        {
            // if not visited mark as visited and add to queue
            if (!vis[e])
            {
                vis[e] = true;
                q.push(e);
            }
        }
    }
    return res;
}
//     }
// };
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<int> adj[v];
        int a, b;
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b); // directed graph
        }
        // Solution o;
        vector<int> ans = bfs(v, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}