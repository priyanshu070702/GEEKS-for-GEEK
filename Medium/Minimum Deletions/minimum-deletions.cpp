//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solveRec(string s, string rev, int i, int j, vector<vector<int>>&dp){
        if(i==s.length() || j==rev.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(s[i]==rev[j]){
            take=1+solveRec(s,rev,i+1,j+1,dp);
        }
        int notTake=max(solveRec(s,rev,i+1,j,dp),solveRec(s,rev,i,j+1,dp));
        return dp[i][j]=max(take,notTake);
    }
    int solveTab(string s, string rev){
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int take=0;
                if(s[i]==rev[j]){
                    take=1+dp[i+1][j+1];
                }
                int notTake=max(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    int minimumNumberOfDeletions(string S) { 
        string rev=S;
        reverse(rev.begin(),rev.end());
        int n=S.length();
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int lonP=solveTab(S,rev);
        return n-lonP;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends