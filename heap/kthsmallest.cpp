#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<int> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push(a[i]);
        if (maxh.size() > k)
            maxh.pop();
    }
    cout << maxh.top() << endl;
    return 0;
}