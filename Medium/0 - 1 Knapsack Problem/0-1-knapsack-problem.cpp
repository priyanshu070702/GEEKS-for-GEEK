//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solveRec(int W, int wt[], int val[], int n, int idx){
        //base case
        if(W==0 || idx==n)return 0;
        
        //include
        int include=0;
        int exclude=0;
        if(wt[idx]<=W){
            int include1=val[idx]+solveRec(W-wt[idx],wt,val,n,idx+1);
            int include2=solveRec(W,wt,val,n,idx+1);
            include=max(include1,include2);
        }
        //exclude
        else{
            exclude=solveRec(W,wt,val,n,idx+1);
        }
        return max(include,exclude);
    }
    int solveMemo(int W, int wt[], int val[], int n, int idx, vector<vector<int>>&dp){
        //base case
        if(W==0 || idx==n)return 0;
        if(dp[W][idx]!=-1)return dp[W][idx];
        //include
        int include=0;
        int exclude=0;
        if(wt[idx]<=W){
            int include1=val[idx]+solveMemo(W-wt[idx],wt,val,n,idx+1,dp);
            int include2=solveMemo(W,wt,val,n,idx+1,dp);
            include=max(include1,include2);
        }
        //exclude
        else{
            exclude=solveMemo(W,wt,val,n,idx+1,dp);
        }
        return dp[W][idx] = max(include,exclude);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //return solveRec(W,wt,val,n,0);
       //memoization
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return solveMemo(W,wt,val,n,0,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends