//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //recursion
    int maxRec(int arr[],int n,int i){
        if(i>=n)return 0;
        //exclude
        int exclude=maxRec(arr,n,i+1);
        //include
        int include=arr[i]+maxRec(arr,n,i+2);
         
        return max(exclude,include);
    }
    
    int maxMemo(int arr[], int n ,int i, vector<int>&dp){
        if(i>=n)return 0;
        //exclude
        if(dp[i]!=-1)return dp[i];
        int exclude=maxMemo(arr,n,i+1,dp);
        //include
        int include=arr[i]+maxMemo(arr,n,i+2,dp);
         
        dp[i] = max(exclude,include);
        return dp[i];
    }
    int FindMaxSum(int arr[], int n)
    {
        //recursion
        // int ans=maxRec(arr,n,0);
        // return ans;
        
        //memoization
        vector<int>dp(n+1,-1);
        int ans=maxMemo(arr,n,0,dp);
        return ans;
        
        // vector<int> dp(n);
        // for(int i=0;i<n;i++){
        //     if(i==0){
        //         dp[i]=arr[i];
        //     }else if(i==1){
        //         dp[i]=max(arr[i],arr[i-1]);
        //     }else{
        //         dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
        //     }
        // }
        // return dp[n-1];
        
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends