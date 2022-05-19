#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int weight;
};
bool compare(struct item a, struct item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return (r1 > r2);
}
double fractionalknap(struct item arr[], int n, int w)
{
    sort(arr, arr + n, compare);
    int cur = 0;
    double final = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (cur + arr[i].weight <= w)
        {
            cur += arr[i].weight;
            final += arr[i].value;
        }
        else
        {
            int remain = w - cur;
            final += arr[i].value * ((double)remain / (double)arr[i].weight);
        }
    }
    return final;
}
int main()
{
    int n, w;
    cin >> n >> w;
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i].value = a;
        arr[i].weight = b;
    }
    cout << fractionalknap(arr, n, w);
    return 0;
}