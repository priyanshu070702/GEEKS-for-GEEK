//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int cut_rec(int n,int x,int y,int z){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        
        int cut_x=1+cut_rec(n-x,x,y,z);
        int cut_y=1+cut_rec(n-y,x,y,z);
        int cut_z=1+cut_rec(n-z,x,y,z);
        
        return max(cut_x,max(cut_y,cut_z));
    }
    //memoization
    int cut_memo(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        
        if(dp[n]!=-1)return dp[n];
        
        int cut_x=1+cut_memo(n-x,x,y,z,dp);
        int cut_y=1+cut_memo(n-y,x,y,z,dp);
        int cut_z=1+cut_memo(n-z,x,y,z,dp);
        
        dp[n]=max(cut_x,max(cut_y,cut_z));
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z){
        //return cut_rec(n,x,y,z); n
        //memoization
        vector<int>dp(n+1,-1);
        int ans = cut_memo(n,x,y,z,dp);
        if(ans<0)return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends