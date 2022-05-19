#include <bits/stdc++.h>
using namespace std;
int posteval(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            st.push(c - '0'); // this will convert the 0 char to int
        }
        else
        {
            int ans;
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (c == '*')
                ans = b * a;
            else if (c == '/')
                ans = b / a;
            else if (c == '+')
                ans = b + a;
            else
                ans = b - a;
            st.push(ans);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << posteval(s);
    return 0;
}