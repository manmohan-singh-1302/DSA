#include <bits/stdc++.h>
using namespace std;
struct bill
{
    string trans_id;
    vector<pair<int, int>> paid_by;
    vector<pair<int, int>> split_as;
};
int main()
{
    int n, m;
    cin >> n >> m;
    bill arr[m];
    int borrowed[n];
    int paid[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].trans_id;
        int a, b;
        cin >> a >> b;
        arr[i].paid_by.resize(a);
        arr[i].split_as.resize(b);
        for (int j = 0; j < a; j++)
        {
            cin >> arr[i].paid_by[j].first;
            cin >> arr[i].paid_by[j].second;
        }
        for (int j = 0; j < b; j++)
        {
            cin >> arr[i].split_as[j].first;
            cin >> arr[i].split_as[j].second;
        }
        int bollowed[n];
        int paid[n];
        for(auto i: arr){
            
        }
        return 0;
    }
}