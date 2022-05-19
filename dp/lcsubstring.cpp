/* same like longest common subsequence except we have to check the length
of the longest common substring i.e. it has to be continous
If its not continous then start the procedure from the beginning*/

#include <bits/stdc++.h>
using namespace std;
int solve(string s1, string s2, int n, int m, int count)
{
    if (n == 0 || m == 0)
        return count;
    if (s1[n - 1] == s2[m - 1])
        count = solve(s1, s2, n - 1, m - 1, count + 1);
    else
        count = max(count, max(solve(s1, s2, n, m - 1, 0), solve(s1, s2, n - 1, m, 0)));
    return count;
}
int main()
{
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;
    cout << solve(s1, s2, n, m, 0);
    return 0;
}

// TABULATION METHOD

#include <bits/stdc++.h>
using namespace std;
int solve(string s1, string s2, int n, int m, int count)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = 0;
        }
    }
    // to obtain the optimal answer traverse through the array and check for
    // the maximum value of the array
    int ans = INT_MIN;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            ans = max(ans, t[i][j]);
        }
    }
    return ans;
}
int main()
{
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;
    cout << solve(s1, s2, n, m, 0);
    return 0;
}
