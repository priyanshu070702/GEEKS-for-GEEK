//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int solveRec(int n, vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int add=0,mul=0;
        if(n%2!=0){
            add=1+solveRec(n-1,dp);
        }
        if(n%2==0){
            mul=1+solveRec(n/2,dp);
        }
        return dp[n]=add+mul;
    }
    int minOperation(int n)
    {
        vector<int>dp(n+1,-1);
        return solveRec(n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends