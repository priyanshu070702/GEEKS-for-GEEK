//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s){
	    int mod=1000000007;
	    int n=s.size();
	    vector<int>dp(n+1,0);
	    dp[0]=1;
	    unordered_map<char,int>mp;
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=(dp[i-1]*2)%mod;
	        if(mp.find(s[i-1])!=mp.end())
	        {
	            char ch=s[i-1];
	            dp[i]=(dp[i]-dp[mp[ch]-1]+mod)%mod;
	            
	            
	        }
	        mp[s[i-1]]=i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends