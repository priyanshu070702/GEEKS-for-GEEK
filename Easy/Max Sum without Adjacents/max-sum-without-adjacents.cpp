//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solveRec(int *arr, int n, int idx, vector<int>&dp){
	    if(idx>=n)return 0;
	    if(dp[idx]!=-1)return dp[idx];
	    int take=arr[idx]+solveRec(arr,n,idx+2,dp);
	    int notTake=solveRec(arr,n,idx+1,dp);
	    return dp[idx]=max(take,notTake);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    return solveRec(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends