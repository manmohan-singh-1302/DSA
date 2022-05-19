#include <bits/stdc++.h>
#define max 1000
using namespace std;
void printpath(int i, int j, int m[max][max], int n, string path)
{
    // if the current pointer is out of boundry then return
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || m[i][j] == 0)
        return;
    // if the current pointer has reached the destination return the path
    if (i == n - 1 && j == n - 1)
    {
        cout << path << endl;
        return;
    }
    m[i][j] = 0; // make it as 0 to avoid going back to same place and avoid infinte loop
    printpath(i + 1, j, m, n, path + 'D');
    printpath(i, j + 1, m, n, path + 'R');
    printpath(i - 1, j, m, n, path + 'U');
    printpath(i, j - 1, m, n, path + 'L');
    m[i][j] = 1; // rechange it again to one
}
int main()
{
    int n;
    cin >> n;
    int m[max][max];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    printpath(0, 0, m, n, "");
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>&ans,vector<vector<int>> m,int n,int i,int j,string posans){
        if(i<0 or j<0 or i>=n or j>=n)return;
        if(m[i][j]==0)return;
        if(i==n-1 and j==n-1){ans.push_back(posans);return;}
        m[i][j]=0;
        solve(ans,m,n,i+1,j,posans+'D');
        solve(ans,m,n,i,j+1,posans+'R');
        solve(ans,m,n,i-1,j,posans+'U');
        solve(ans,m,n,i,j-1,posans+'L');
        m[i][j]=1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string>ans;
        solve(ans,m,n,0,0,"");
        return ans;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} */