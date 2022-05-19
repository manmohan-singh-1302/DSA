#include <bits/stdc++.h>
using namespace std;
int t[100];
int fib(int n)
{
    memset(t, -1, sizeof(t));
    if (n <= 1)
        return t[n] = n;
    if (t[n] != -1)
        return t[n];
    else
    {
        return t[n] = fib(n - 1) + fib(n - 2);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}

/*
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
   long dp[101];
    long long func(long n)
    {
        if(n<=2) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = func(n-1) + func(n-2);
    }

    vector<long long> printFibb(int n)
    {
        //code here
        vector<long long > ans;
        memset(dp,-1,sizeof(dp));
        for(long i=1;i<=n;i++)
        {
            ans.push_back(func(i));
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
  */