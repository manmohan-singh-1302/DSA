#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, string s1, string s2)
{
    int t[a + 1][b + 1];
    for (int i = 0; i < a + 1; i++)
    {
        for (int j = 0; j < b + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < a + 1; i++)
    {
        for (int j = 1; j < b + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[a][b];
}
//     if (a == 0 || b == 0)
//     {
//         return 0;
//     }
//     if (s1[a - 1] == s2[b - 1])
//     {
//         return 1 + solve(a - 1, b - 1, s1, s2);
//     }
//     else
//     {
//         return max(solve(a - 1, b, s1, s2), solve(a, b - 1, s1, s2));
//     }
// }
int main()
{
    int a, b;
    string s1, s2;
    cin >> a >> b;
    cin >> s1 >> s2;
    cout << solve(a, b, s1, s2);
    return 0;
}