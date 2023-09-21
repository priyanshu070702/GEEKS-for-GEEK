//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solveRec(int arr[], int n, int idx, vector<int>&dp){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int take=arr[idx]+solveRec(arr,n,idx+2,dp);
        int notTake=solveRec(arr,n,idx+1,dp);
        
        return dp[idx]=max(take,notTake);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+1,-1);
        return solveRec(arr,n,0,dp);
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