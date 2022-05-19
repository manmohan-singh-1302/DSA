#include <bits/stdc++.h>
using namespace std;
void maxmeetings(int s[], int f[], int n)
{
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].first = f[i];
        a[i].second = i;
    }
    sort(a, a + n);
    int tl = a[0].first;
    vector<int> m;
    m.push_back(a[0].second + 1);
    for (int i = 1; i < n; i++)
    {
        if (s[a[i].second] > tl)
        {
            m.push_back(a[i].second + 1);
            tl = a[i].first;
        }
    }
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int s[n], f[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    maxmeetings(s, f, n);
    return 0;
}

// the time complexity of this algorithm is o(n);
// the space complexity of this algorithm is s(n);l