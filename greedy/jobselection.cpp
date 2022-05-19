#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}
void solve(Job a[], int n)
{
    sort(a, a + n, compare);
    bool slot[n]; // to keep track of the time
    int ans[n];   // to store the resultant answer
    for (int i = 0; i < n; i++)
    {
        slot[i] = false; // initially evey slot is empty
    }
    for (int i = 0; i < n; i++)
    { // iterate over the jobs
        for (int j = min(n, a[i].deadline) - 1; j >= 0; j--)
        { // to check whether the slot is free or not from the last possible job
            if (slot[j] == false)
            {
                slot[j] = true;
                ans[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            cout << a[ans[i]].id << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    Job a[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].id = x;
        a[i].deadline = y;
        a[i].profit = z;
    }
    solve(a, n);
    return 0;
}