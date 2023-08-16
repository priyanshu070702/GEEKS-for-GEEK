//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int mod=1e9+7;
    int solveRec(int l, int r, vector<vector<int>>&dp){
        if(l==0 && r==0)return 1;
        
        if(dp[l][r]!=-1)return dp[l][r]%mod;
        int left=0;
        if(l>0){
            left+= solveRec(l-1,r,dp);
        }
        int right=0;
        if(r>0 && l<r){
            right+=solveRec(l,r-1,dp);
        }
        
        return dp[l][r]= ((left%mod)+(right%mod));
    }
    int solveTab(int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //dp[0][0]=1;
        for(int l=0;l<=n;l++){
            for(int r=0;r<=n;r++){
                if (l == 0 && r == 0) {
                dp[l][r] = 1;
            }else{
                int left=0;
                if(l>0){
                    left= dp[l-1][r];
                }
                int right=0;
                if(r>0 && l<r){
                    right=dp[l][r-1];
                }
                dp[l][r]= ((left%mod)+(right%mod));
            }
            }
        }
        return dp[n][n];
    }
    int findCatalan(int n) 
    {
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        // return solveRec(n,n,dp);
        return solveTab(n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends