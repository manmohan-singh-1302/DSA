#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0; // the starting index of the window
    int j = 0; // the ending index of the window
    // window size can be calculated by (j-i+1)
    int sum = 0;
    int ans = INT_MIN;
    while (j < n)
    {
        sum += arr[j];
        if ((j - i + 1) < k)
            j++; // increases the window size
        else if ((j - i + 1) == k)
        {
            // mainting the window size and calculating the cummulative sum
            ans = max(ans, sum);
            sum -= arr[i];
            j++;
            i++;
        }
    }
    cout << "the maximum sum of the subarray of k size is" << ans << endl;
    return 0;
}
// the time complexity of this code is O(n)
//  the space complexity of this code is S(1)