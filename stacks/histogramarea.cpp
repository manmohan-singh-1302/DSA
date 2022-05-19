#include <bits/stdc++.h>
using namespace std;
// next greatest element to right problem using the stack
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> left(n), right(n);
    stack<long long> s;
    // nsl

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left[i] = -1;
        }
        else
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                // cout << s.top() << endl;
                s.pop();
            }
            if (s.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = s.top();
            }
        }
        s.push(i);
    }

    // empty stack
    while (!s.empty())
    {
        s.pop();
    }

    // nsr
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            right[j++] = n;
        }
        else
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                right[j++] = n;
            }
            else
            {
                right[j++] = s.top();
            }
        }
        s.push(i);
    }

    reverse(right.begin(), right.end());

    // calculation of width
    for (int i = 0; i < n; i++)
    {
        left[i] = right[i] - left[i] - 1;
    }

    long long ans = INT_MIN;
    // calculate getMaxArea
    for (int i = 0; i < n; i++)
    {
        long x = left[i] * arr[i];
        if (x > ans)
        {
            ans = x;
        }
    }
    return ans;
    return 0;
}
