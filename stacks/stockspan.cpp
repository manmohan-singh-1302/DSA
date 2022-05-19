#include <bits/stdc++.h>
using namespace std;
// stock span is the problem which is used to depict the day for which the price of the stack is the highest
// i.e.  the maximum number of consecutive days just before the given day, for which the price of the stock
// on the current day is less than its price on the given day.

// Calcutate the nearest greatest element to left's index and subtract it from the current index
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<pair<int, int>> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > a[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() && s.top().first <= a[i])
        {
            while (s.size() > 0 && s.top().first <= a[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({a[i], i});
    }
    for (int i = 0; i < n; i++)
        v[i] = i - v[i];
    for (auto i : v)
        cout << i << " ";
    return 0;
}