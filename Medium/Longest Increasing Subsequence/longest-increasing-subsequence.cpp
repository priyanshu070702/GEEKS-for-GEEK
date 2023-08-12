//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solveRec(int n, int a[], int prev, int curr, vector<vector<int>>&dp){
        if(curr==n)return 0;
        
        if(dp[prev+1][curr]!=-1)return dp[prev+1][curr];
        //include condition
        int include=0;
        if(prev==-1 || a[curr]>a[prev]){
            include=1+solveRec(n,a,curr,curr+1,dp);
        }
        //exclude condition
        int exclude=solveRec(n,a,prev,curr+1,dp);
        
        return dp[prev+1][curr]=max(include, exclude);
    }
    int spaceOptimal(int n, int nums[]){
        if(n==0)return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else {
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
    //   vector<vector<int>>dp(n+2,vector<int>(n+1,-1));
    //   return solveRec(n,a,-1,0,dp);
    return spaceOptimal(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends