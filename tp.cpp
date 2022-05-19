#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
        u[arr[i]]++;
    vector<int> occ(n + 1, 0);
    for (auto it : u)
        occ[it.second]++;
    int ans = occ.size();
    for (int i = 1; i <= n; i++)
    {
        int temp = occ[i];
        if (temp == 0)
            continue;
        int t = min(temp, m / i);
        ans -= t;
        m -= i * t;
    }
    cout << ans << endl;
    return 0;
}