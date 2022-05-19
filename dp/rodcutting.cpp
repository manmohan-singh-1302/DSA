#include <bits/stdc++.h>
using namespace std;
int solve(int price[], int length[],
          int Max_len, int n)
{

    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene  we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len] = max(price[n - 1] + un_kp(price, length,
                                                 Max_len - length[n - 1], n),
                            un_kp(price, length, Max_len, n - 1));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        t[n][Max_len] = un_kp(price, length,
                              Max_len, n - 1);
    }

    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_lenth column.
    return t[n][Max_len];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cout << solve(arr, p, n, n);
}