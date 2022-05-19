#include <bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0) // if there are no elemets in the array then return 0
                t[i][j] = false;
            if (j == 0) // if the required sum is found then return 1
            {
                t[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j) // if the current element is larger then the sum then ignore the element
            {
                t[i][j] = t[i - 1][j];
            }
            else // include or not include the current element            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
        }
    }
}
return t[n][sum];
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, n, sum);
    return 0;
}