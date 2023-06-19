//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minRec(int coins[], int M, int V){
	    //base case
	    if(V==0)return 0;
	    if(V<0)return INT_MAX;
	    int res=INT_MAX;
	    for(int i=0;i<M;i++){
	        int ans=minRec(coins,M,V-coins[i]);
	        if(ans!=INT_MAX){
	            res=min(res,1+ans);
	        }
	    }
	    return res;
	}
	int minMemo(int coins[],int M, int V, vector<int>&dp){
	    if(V==0)return 0;
	    if(V<0)return INT_MAX;
	    int res=INT_MAX;
	    if(dp[V]!=-1)return dp[V];
	    for(int i=0;i<M;i++){
	        int ans=minMemo(coins,M,V-coins[i],dp);
	        if(ans!=INT_MAX){
	            res=min(res,1+ans);
	        }
	    }
	    dp[V]=res;
	    return dp[V];
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	   //recursion exponential 
	   // int ans=minRec(coins,M,V);
	   // if(ans==INT_MAX)return -1;
	   // return ans;
	   
	   //memoization O(n*n);
	   vector<int>dp(V+1,-1);
	   int ans = minMemo(coins,M,V,dp);
	   if(ans==INT_MAX)return -1;
	   return ans;
	   
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends