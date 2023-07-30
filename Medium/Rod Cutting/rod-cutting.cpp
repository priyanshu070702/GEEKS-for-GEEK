//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solveMemo(int price[], int n, int idx, int sz, vector<vector<int>>&dp){
        if(idx==sz)return 0;
        if(n==0)return 0;
        
        if(dp[n][idx]!=-1)return dp[n][idx];
        //take
        int take=INT_MIN;
        if(idx+1<=n){
            take=price[idx]+solveMemo(price,n-(idx+1),idx,sz,dp);
        }
        //not take
        int not_take=solveMemo(price,n,idx+1,sz,dp);
        
        return dp[n][idx] = max(take,not_take);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(price,n,0,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends