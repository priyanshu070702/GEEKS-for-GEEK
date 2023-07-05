//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg

class Solution {
  public:
    int stockMemo(vector<int>&prices, int n, int index, bool buy, vector<vector<int>>&dp){
        if(index>=n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy==1){
            profit=max((-prices[index]+stockMemo(prices,n,index+1,0,dp)),
                       stockMemo(prices,n,index+1,1,dp));
        }
        else if(buy==0){
            profit=max((prices[index]+stockMemo(prices,n,index+1,1,dp)),
                       stockMemo(prices,n,index+1,0,dp));
        }
        return dp[index][buy] = profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return stockMemo(prices,n,0,1,dp);
        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1]){
                ans+=(prices[i+1]-prices[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends