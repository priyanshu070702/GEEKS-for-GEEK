//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod=1e9+7;
public:
    int solve(int n, int r, vector<vector<int>>&dp){
        if(r == 0 || r == n){
            return 1;
        }
        if(dp[n][r] != -1)
            return dp[n][r];
        
        dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
        return dp[n][r];
    }
    int nCr(int n, int r){
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(n,r,dp);
        if(r>n)return 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r]%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends