#include <bits/stdc++.h>
using namespace std;
int knapsack(int w, int p[], int wt[], int n)
{
    if (n == 0 || w == 0) // if there are no elements or the remaining
        // weight of the bag is zero then return 0
        return 0;
    if (wt[n - 1] > w) // if the weight of the last element is greater than
    // the bag's weight dont include it
    {
        return knapsack(w, p, wt, n - 1);
    }
    else
    // now we have two choice i.e. to include the element into the knapsack
    // or not. If we are including it decrease the weight of the bag by the
    // last elements weight, or if we are not including the element just remove the
    // last element.
    {
        return max(p[n - 1] + knapsack(w - wt[n - 1], p, wt, n - 1), knapsack(w, p, wt, n - 1));
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
    cout << knapsack(w, p, wt, n);
}