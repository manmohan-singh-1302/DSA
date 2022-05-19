#include <bits/stdc++.h>
using namespace std;
void subsequence(string in, string out)
{
    if (in.length() == 0)
    {
        cout << out << endl;
        return;
    }
    subsequence(in.substr(1), out + in[0]);
    subsequence(in.substr(1), out);
}
int main()
{
    string in;
    cin >> in;
    string out = "";
    subsequence(in, out);
    return 0;
}
// taking input is messing the output don't know why?, so give manual input for the string.
