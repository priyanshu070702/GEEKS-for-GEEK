//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int solveRec(int amount, int coins[], int idx, vector<vector<long long int>>&dp, int N){
        if(amount<0 || idx>=N)return 0;
        if(amount==0)return 1;
        if(dp[amount][idx]!=-1)return dp[amount][idx];
        //take
        long long int take=0;
        if(coins[idx]<=amount){
            take=solveRec(amount-coins[idx], coins, idx, dp, N);
        }
        //nottake
        long long int not_take=solveRec(amount, coins, idx+1, dp, N);
        
        return dp[amount][idx]=(take+not_take);
    }
    long long int solveTab(int coins[], int N, int sum){
        vector<vector<long long int>>dp(sum+2, vector<long long int>(N+2,0));
        for(int i=0;i<=N;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<=sum;i++){
            for(int j=N-1;j>=0;j--){
                
                long long int take=0;
                if(coins[j]<=i){
                    take=dp[i-coins[j]][j];
                }
                long long int not_take=dp[i][j+1];
                
                dp[i][j]=(take+not_take);
            }
        }
        return dp[sum][0];
    }
    long long int count(int coins[], int N, int sum) {
        // vector<vector<long long int>>dp(sum+1, vector<long long int>(N,-1));
        // return solveRec(sum, coins, 0, dp, N);
         return solveTab(coins, N, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends