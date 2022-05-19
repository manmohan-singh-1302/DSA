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
    map<int, int> u;
    for (int i = 0; i < n; i++)
        u[arr[i]]++;

    cout << "size " << u.size() << endl;
    while (m >= 0)
    {
        bool flag = false;
        for (auto i : u)
        {
            if (m <= i.second)
            {
                flag = true;
                break;
            }
            // if (m >= i.second)
            // {
            m -= i.second;
            cout << m << endl;
            int ans = i.first;
            u.erase(ans);
            // }
        }
        if (flag)
            break;
    }
    cout << u.size() << endl;
    return 0;
}