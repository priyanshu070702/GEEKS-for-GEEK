//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solveRec(string str, int idx, int sum, vector<vector<int>>&dp){
	    if(idx>=str.length())return 1;
	    if(dp[idx][sum]!=-1)return dp[idx][sum];
	    int ans=0;
	    int c_sum=0;
	    for(int i=idx;i<str.length();i++){
	        c_sum+=str[i]-'0';
	        if(c_sum>=sum)ans+=solveRec(str,i+1,c_sum,dp);
	    }
	    return dp[idx][sum]=ans;
	}
	int TotalCount(string str){
	    int sum=0;
	    for(int i=0;i<str.length();i++){
	        sum+=str[i]-'0';
	    }
	    vector<vector<int>>dp(str.length(),vector<int>(sum+1,-1));
	    return solveRec(str,0,0,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends