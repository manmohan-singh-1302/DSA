/* This program is to print the k largest elements from a given unsorted array
In order to print the largest element from an unsorted array construct a min heap
with size k and follow the standard procedure then assign the elements of the min
heap to an array and reverse it*/

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
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(a[i]);
        if (minh.size() > k)
            minh.pop();
    }
    vector<int> ans;
    while (k > 0)
    {
        ans.push_back(minh.top());
        minh.pop();
        k--;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}