//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int solveRec(vector<int>&price, int idx, bool val, int times, vector<vector<vector<int>>>&dp){
            if(times==0)return 0;
            if(idx==price.size())return 0;
            if(dp[idx][val][times]!=-1)return dp[idx][val][times];
            int take=0,notTake=0;
            if(val){
                take=max(-price[idx]+solveRec(price,idx+1,0,times,dp),solveRec(price,idx+1,1,times,dp));
            }
            else{
                notTake=max(price[idx]+solveRec(price,idx+1,1,times-1,dp),solveRec(price,idx+1,0,times,dp));
            }
            return dp[idx][val][times]=max(take,notTake);
        }
        int solveTab(vector<int>&price){
            int n=price.size();
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            for(int idx=n-1;idx>=0;idx--){
                for(int val=0;val<=1;val++){
                    for(int times=1;times<=2;times++){
                        int take=0,notTake=0;
                        if(val){
                            take=max(-price[idx]+dp[idx+1][0][times],dp[idx+1][1][times]);
                        }
                        else{
                            notTake=max(price[idx]+dp[idx+1][1][times-1],dp[idx+1][0][times]);
                        }
                        dp[idx][val][times]=max(take,notTake);
                    }
                }
            }
            return dp[0][1][2];
        }
        int maxProfit(vector<int>&price){
            // int n=price.size();
            // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
            // return solveRec(price,0,1,2,dp);
            return solveTab(price);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends