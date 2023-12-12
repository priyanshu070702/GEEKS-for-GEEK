//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int fun(vector<vector<int>> &M,int n,int m,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int n1=fun(M,n,m,i-1,j+1,dp);
        int n2=fun(M,n,m,i,j+1,dp);
        int n3=fun(M,n,m,i+1,j+1,dp);
        
        return dp[i][j]=M[i][j]+max(max(n1,n2),n3);
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int k=fun(M,n,m,i,0,dp);
            if(k>ans)
                ans=k;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends