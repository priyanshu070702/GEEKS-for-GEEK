//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // //Function to find length of longest increasing subsequence.
    // int solveMemo(int nums[], int n, int curr, int prev){
    //     if(curr==n)return 0;
    //     if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
    //     //include
    //     int include=0;
    //     if(prev==-1 || nums[curr]>nums[prev]){
    //         include=1+solveMemo(nums,n,curr+1,curr);
    //     }
    //     //exclude
    //     int exclude=solveMemo(nums,n,curr+1,prev);
    //     return dp[curr][prev+1]=max(include,exclude);
    // }
    int solveTab(int n, int nums[]){
        vector<int>cu(n+1,0);
        vector<int>nxt(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int include=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                   include=1+nxt[curr+1];
                }
                //exclude
                int exclude=nxt[prev+1];
                
                cu[prev+1]=max(include,exclude);
            }
            nxt=cu;
        }
        return nxt[0];
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