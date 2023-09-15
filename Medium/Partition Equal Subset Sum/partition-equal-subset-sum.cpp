//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solveRec(int N, int arr[], int sum, int idx, vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(idx>=N)return 0;
        
        if(dp[sum][idx]!=-1)return dp[sum][idx];
        
        int take=0;
        if(arr[idx]<=sum){
            take=solveRec(N, arr, sum-arr[idx], idx+1,dp);
        }
        int notTake=solveRec(N, arr, sum, idx+1, dp);
        
        return dp[sum][idx] = take||notTake;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        vector<vector<int>>dp(sum+1, vector<int>(N+1,-1));
        return solveRec(N,arr,sum/2,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends