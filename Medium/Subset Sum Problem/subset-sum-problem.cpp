//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool sumRec(vector<int>arr,int n,int sum, int index){
        if(index>=n)return false;
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }
        bool include=sumRec(arr,n,sum-arr[index],index+1);
        bool exclude=sumRec(arr,n,sum,index+1);
        
        return include||exclude;
    }
    bool sumMemo(vector<int>arr,int n,int sum, int index,vector<vector<int>>&dp){
        if(index==n-1){
            if(sum==0|| sum==arr[index]){
                return true;
            }
            return false;
        }
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool include=false;
        if(arr[index]<=sum){
        include=sumMemo(arr,n,sum-arr[index],index+1,dp);
        }
        bool exclude=sumMemo(arr,n,sum,index+1,dp);
        
        return dp[index][sum] = include||exclude;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        // bool ans=0;
        //return sumRec(arr,n,sum,0);
        vector<vector<int>>dp(n+2,vector<int>(sum+1,-1));
        return sumMemo(arr,n,sum,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends