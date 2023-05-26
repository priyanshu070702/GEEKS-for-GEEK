//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    int dfs(int n, int i, int l, int x, vector<vector<int>> &dp) {
        if(!n) return 1;
        if(i > l) return 0;
        if(dp[n][i] != -1) return dp[n][i];
        
        int notpick = dfs(n, i + 1, l, x, dp);
        int pick = n - pow(i, x) >= 0 ? dfs(n - pow(i, x), i + 1, l, x, dp) : 0;
        
        return dp[n][i] = (pick + notpick) % 1000000007;
    }
    public:
    int numOfWays(int n, int x) {
        int l = pow(n, 1.0 / x);
        vector<vector<int>> dp(n + 1, vector<int>(l + 1, -1));
        return dfs(n, 1, l, x, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends