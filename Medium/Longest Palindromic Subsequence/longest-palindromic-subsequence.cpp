//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solveRec(string A, string B, int n, int i, int j,vector<vector<int>>&dp){
        if(i>=n || j>=n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(A[i]==B[j]){
            ans=1+solveRec(A,B,n,i+1,j+1,dp);
        }
        else{
            ans=max(solveRec(A,B,n,i+1,j,dp),solveRec(A,B,n,i,j+1,dp));
        }
        return dp[i][j]=ans;
    } 
    int longestPalinSubseq(string A) {
        string B=A;
        reverse(B.begin(),B.end());
        int n=B.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveRec(A,B,n,0,0,dp);
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