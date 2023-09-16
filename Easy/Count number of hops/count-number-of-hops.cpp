//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int mod=1e9+7;
    public:
    long long solveRec(int n, int idx, vector<int>&dp){
        if(idx==n)return 1;
        if(idx>n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long one_step=solveRec(n,idx+1,dp);
        long long two_step=solveRec(n,idx+2,dp);
        long long three_step=solveRec(n, idx+3,dp);
        
        return dp[idx] = ((one_step%mod)+(two_step%mod)+(three_step%mod))%mod;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n){
        vector<int>dp(n+1,-1);
        return solveRec(n, 0, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends