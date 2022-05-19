// ::::::::::::::
// ::: NITISH :::
// ::::::::::::::
// #include <iostream>
#include <bits/stdc++.h>
// #include <cstring>
#define vi vector<long long int>
#define vc vector<char>
#define rep(i, j, n) for (long long int i = j; i < n; i++)
#define pb(a) push_back(a)
#define sz(x) (int)((x).size())
// #define int long long int
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / __gcd(a, b)
#define ll long long
#define all(a) a.begin(), a.end()
const int maxi = 1e5;
#include <math.h>
using namespace std;
// use scanf and printf instead of cin and cout. (0.25sec and 1.2 sec respectively)
int n, m;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v)
{
    color[v] = 1;
    // cout<<"v"<<" "<<v<<endl;
    for (int u : adj[v])
    {
        // cout<<"u"<<" "<<u<<endl;
        if (color[u] == 0)
        {
            parent[u] = v;
            if (dfs(u))
            {
                // cout<<"entered"<<endl;
                return true;
            }
        }
        else if (color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            // cout<<"v"<<" "<<v<<endl;
            // cout<<"entered"<<endl;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle()
{
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
    {
        // cout<<"dfs"<<" "<<dfs(v)<<endl;
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "Acyclic" << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n);
    // for(int i=0;i<n;i++){
    //   adj[i].resize(m);
    // }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    // for(int i=0;i<n;i++){
    //   cout<<i<<" ";
    //   for(auto it: adj[i]){
    //     cout<<it<<" ";
    //   }
    //   cout<<endl;
    // }
    find_cycle();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}

// with out coloring
#include <bits/stdc++.h>
using namespace std;
bool cycleUtil(int s, vector<bool> &vis, vector<bool> &res, vector<int> adj[])
{
    if (vis[s] == false)
    {
        vis[s] = true;
        res[s] = true;
        for (int i = 0; i < (int)adj[s].size(); i++)
        {
            if (!vis[adj[s][i]] && cycleUtil(adj[s][i], vis, res, adj))
                return true;
            else if (res[adj[s][i]])
                return true;
        }
    }
    res[s] = false;
    return false;
}
bool cycle(vector<int> adj[], int v)
{
    vector<bool> vis(v, false);
    vector<bool> res(v, false);
    for (int i = 0; i < v; i++)
    {
        if (cycleUtil(i, vis, res, adj))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    if (cycle(adj, v))
    {
        cout << "cyclic" << endl;
    }
    else
    {
        cout << "acyclic" << endl;
    }
    return 0;
}