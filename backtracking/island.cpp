#include <iostream>
#include <vector>
using namespace std;
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
int island(vector<vector<int>> &v, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
            {
                v[i][j] = 2;
                count++;
                dfs(v, i + 1, j, n);
                dfs(v, i - 1, j, n);
                dfs(v, i, j - 1, n);
                dfs(v, i, j + 1, n);
            }
        }
    }
    return count;
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
    cout << island(v, n);
}

/*

#include <iostream>
#include <vector>
using namespace std;
int island(vector<vector<int>> &v, int n, int i, int j)
{
	if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || v[i][j] != 1)
		return;
	int count = 0;
	v[i][j] = 2;
	island(v, i + 1, j, n);
	island(v, i - 1, j, n);
	island(v, i, j - 1, n);
	island(v, i, j + 1, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1)
				count++;
		}
	}
	return count;
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
	cout << island(v, n, 0, 0);
}

*/