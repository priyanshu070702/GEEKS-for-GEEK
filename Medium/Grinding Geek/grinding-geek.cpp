//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solveRec(int idx, int n, int total, vector<int>cost, vector<vector<int>>&dp){
        if(idx>=n)return 0;
        int take=0;
        if(dp[idx][total]!=-1)return dp[idx][total];
        if(cost[idx]<=total){
            take=1+solveRec(idx+1,n,total-cost[idx]+(int)floor(0.9*cost[idx]),cost,dp);
        }
        int notTake=solveRec(idx+1,n,total,cost,dp);
        return dp[idx][total]=max(take,notTake);
    }
    int solveTab(int n, int tot, vector<int>cost){
        vector<vector<int>>dp(n+1,vector<int>(tot+1,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int total=0;total<=tot;total++){
                int take=0;
                if(cost[idx]<=total){
                    take=1+dp[idx+1][total-cost[idx]+(int)floor(0.9*cost[idx])];
                }
                int notTake=dp[idx+1][total];;
                dp[idx][total]=max(take,notTake);
            }
        }
        return dp[0][tot];
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        // vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return solveTab(n,total,cost);
        //return solveRec(0,n,total,cost,dp);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends