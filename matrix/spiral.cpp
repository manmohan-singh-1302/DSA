#include <bits/stdc++.h>
using namespace std;
void spiral(vector<vector<int>> v, int m, int n)
{
    int k = 0; // pointer to check the starting row index
    int l = 0; // pointer to check the starting column index
    int i;
    while (k < m && l < n)
    {
        // for loop to print the first row
        //  iterate over the columns inorder to print the rows
        //  iterate over the rows inorder to print the columns

        // first half of the spiral traversal
        // |||||||||
        //         |
        //         |
        //         |

        for (i = l; i < n; i++)
        {
            cout << v[k][i] << " "; // prints first row
        }
        k++;
        for (i = k; i < m; i++)
        {
            cout << v[i][n - 1] << " "; // prints first column
        }
        n--;

        // second half of the spiral traversal

        if (k < m)
        {

            // condition to print the last row

            for (i = n - 1; i >= l; --i)
            {
                cout << v[m - 1][i] << " ";
            }
            m--;
        }

        if (l < n)
        {

            // condition to print the first column

            for (i = m - 1; i >= k; --i)
            {
                cout << v[i][l] << " ";
            }
            l++;
        }
    }
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v;
    v.resize(r);
    for (int i = 0; i < r; i++)
        v[i].resize(c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];
    spiral(v, r, c);
    return 0;
}