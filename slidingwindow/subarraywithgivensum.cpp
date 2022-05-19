#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int arr[], int n, int s)
{
    int i = 0, j = 0, sum = 0;
    vector<int> ans;
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }
        j++;
    }
    if (ans.size() == 0)
    {
        ans.push_back(-1);
        return ans;
    }
}
int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> sol = solve(arr, n, s);
    for (auto i : sol)
    {
        cout << i << " ";
    }
    return 0;
}