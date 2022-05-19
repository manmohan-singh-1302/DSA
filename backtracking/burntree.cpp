#include <iostream>
#include <vector>
using namespace std;
int count = 0;
void dfs(vector<vector<int>> &v, int i, int j, int n)
{
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || v[i][j] != 1)
        return;
    v[i][j] = 2;
    dfs(v, i + 1, j, n);
    dfs(v, i - 1, j, n);
    dfs(v, i, j - 1, n);
    dfs(v, i, j + 1, n);
}
void island(vector<vector<int>> &v, int n)
{
    // int count = 0;
    if (v[0][0] == 0)
        // return count;
        v[0][0] = 2;
    dfs(v, 0 + 1, 0, n);
    dfs(v, 0 - 1, 0, n);
    dfs(v, 0, 0 - 1, n);
    dfs(v, 0, 0 + 1, n);
    // return count;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; i++)
        v[i].resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    island(v, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
                count++;
        }
    }
    cout << count;
}