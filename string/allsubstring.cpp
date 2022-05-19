#include <bits/stdc++.h>
using namespace std;
class substring
{
public:
    vector<string> solve(string s)
    {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            string subStr;
            for (int j = i; j < n; j++)
            {
                subStr += s[j];
                ans.push_back(subStr);
            }
        }
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    substring obj;
    vector<string> sol;
    sol = obj.solve(s);
    for (auto i : sol)
    {
        cout << i << endl;
    }
    return 0;
}