#include <bits/stdc++.h>
using namespace std;
void search(vector<vector<int>> v, int r, int c, int ele)
{
    for (int i = 0; i < v.size(); i++)
    {
        int low = 0;
        int high = v[i].size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[i][mid] == ele)
            {
                cout << "the element found at :" << i << " " << mid << endl;
                return;
            }
            else if (v[i][mid] < ele)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
}
int main()
{
    int r, c, ele;
    cin >> r >> c >> ele;
    vector<vector<int>> v;
    v.resize(r);
    for (int i = 0; i < r; i++)
        v[i].resize(c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    search(v, r, c, ele);
    return 0;
}