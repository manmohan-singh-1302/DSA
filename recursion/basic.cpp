#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    if (n > 0)
    {
        solve(n - 1);
        cout << n << " ";
    }
    else
        return;
}
int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}