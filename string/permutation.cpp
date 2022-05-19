// for a string of length n there will be a total of n! permutations.
//  in order to print all the permutations run a loop and fix a
// character in the string and slice the remaining string
#include <bits/stdc++.h>
using namespace std;
void solve(string in, string op)
{
    if (in.length() == 0)
    {
        cout << op << endl;
    }
    for (int i = 0; i < in.length(); i++)
    {
        char ch = in[i];
        string l_s = in.substr(0, i);
        string r_s = in.substr(i + 1);
        string ans = l_s + r_s;
        solve(ans, op + ch);
    }
}
int main()
{
    string s = "abc";
    // cin >> s;
    solve(s, "");
    return 0;
}