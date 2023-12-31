//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool solveRec(int N, int coins[], int idx, int sum, vector<vector<int>>&dp){
        if(sum>0 && (sum%24==0 || sum%20==0 || sum==2024))return 1;
        if(idx>=N || sum>2024)return 0;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        bool take=solveRec(N,coins,idx+1,sum+coins[idx],dp);
        bool notTake=solveRec(N,coins,idx+1,sum,dp);
        return dp[idx][sum]=take||notTake;
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N+1,vector<int>(2025,-1));
        return solveRec(N,coins,0,0,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends