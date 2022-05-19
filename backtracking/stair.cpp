#include <bits/stdc++.h>
using namespace std;
void stairPath(int n, string path)
{
    if (n < 0) // base case if out of boundary
        return;
    if (n == 0) // base case end point
    {
        cout << path << endl;
        return;
    }
    // recurse by changing the current point or say hopping
    stairPath(n - 1, path + '1');
    stairPath(n - 2, path + '2');
    stairPath(n - 3, path + '3');
}
int main()
{
    int n; // number of stairs
    cin >> n;
    stairPath(n, "");
    return 0;
}
