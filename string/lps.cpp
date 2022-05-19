#include <bits/stdc++.h>
using namespace std;
int lps(string s)
{
    int n = s.length();
    int start = 0;
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int len = 1;
    for (int i = 0; i < n; i++) // every single alphabet is a palindrome and marks diagonal of the table as true
        table[i][i] = 1;
    for (int i = 0; i < n; i++)//checks for palindromic string of length 2
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            len = 2;
        }
    }
    for (int k = 3; k <= n; ++k)    //diagonal as a center checks for the left and right ele as same or not and marks it for variable length
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;
                if (k > len)
                {
                    start = i;
                    len = k;
                }
            }
        }
    }
    for (int d = start; d <= start + len; ++d)
        cout << s[d];
    return len;
}
int main()
{
    string s;
    cin >> s;
    cout << lps(s);
    return 0;
}