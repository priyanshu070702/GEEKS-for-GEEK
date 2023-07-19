//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solveMemo(int i, int j, string A, string  B, int n, vector<vector<int>>&dp){
        if(i==n || j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cnt=0;
        if(A[i]==B[j]){
            cnt+=1+solveMemo(i+1,j+1,A,B,n,dp);
        }
        else{
            cnt+=max(solveMemo(i+1,j,A,B,n,dp),solveMemo(i,j+1,A,B,n,dp));
        }
        return dp[i][j] = cnt;
    }
    int longestPalinSubseq(string A) {
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(0,0,A,B,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends