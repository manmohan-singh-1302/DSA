#include <bits/stdc++.h>
using namespace std;
void sortmat(vector<vector<int>> Mat, int r, int c)
{
    vector<int> vec;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            vec.push_back(Mat[i][j]);
        }
    }
    int k = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            Mat[i][j] = vec.at(k);
            k++;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
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
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    sortmat(v, r, c);
    return 0;
}