// memoization approach

#include <bits/stdc++.h>
using namespace std;
const int d = 1001; // maximum range of the changing variables
static int t[d][d];
int knapsack(int w, int p[], int wt[], int n)
{
    if (n == 0 || w == 0) // if there are no elements or the remaining
        // weight of the bag is zero then return 0
        return 0;
    if (t[n][w] != -1)
    {
        return t[n][w];
    }
    else
    {

        if (wt[n - 1] > w) // if the weight of the last element is greater than
        // the bag's weight dont include it
        {
            t[n][w] = knapsack(w, p, wt, n - 1);
        }
        // now we have two choice i.e. to include the element into the knapsack
        // or not. If we are including it decrease the weight of the bag by the
        // last elements weight, or if we are not including the element just remove the
        // last element.
        else if (wt[n - 1] <= w)
        {
            t[n][w] = max(p[n - 1] + knapsack(w - wt[n - 1], p, wt, n - 1), knapsack(w, p, wt, n - 1));
        }
        return t[n][w];
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int p[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    memset(t, -1, sizeof(t));
    cout << knapsack(w, p, wt, n);
}

// tabulation approach

#include <bits/stdc++.h>
using namespace std;
int knapsack(int w, int p[], int wt[], int n)
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (j >= wt[i - 1])
            {
                t[i][j] = max(p[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}
int main()
{
    int n, w;
    cin >> n >> w;
    int p[n], wt[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << knapsack(w, p, wt, n);
    return 0;
}