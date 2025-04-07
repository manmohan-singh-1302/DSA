#include <bits/stdc++.h>
using namespace std;
int maxsum(int a[], int n)
{
    // iterate over the array and check for the contigous positive elements
    // if element is greater than zero add the value of the element to the sum
    // or else make the element so far(pos) as zero
    // if the sum is less than the pos assign the value of pos to sum
    int sum = INT_MIN, pos = 0;
    for (int i = 0; i < n; i++)
    {
        pos += a[i];
        if (sum < pos)
            sum = pos;
        if (pos < 0)
            pos = 0;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxsum(a, n);
    return 0;
}