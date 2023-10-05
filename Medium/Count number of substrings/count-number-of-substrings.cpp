//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     long long int helper(string s, int k){
        
        if(k == 0)  
            return 0;
        
        long long int ans = 0, distinct = 0;
        vector<int>mp(26, 0);
        
        int i = 0, j = 0, n = s.size();
        
        while(j < n){
            
            ++mp[s[j] - 'a'];
            
            if(mp[s[j] - 'a'] == 1)     
                ++distinct;
            
            while(i < j && distinct > k){
                
                --mp[s[i] - 'a'];
                
                if(mp[s[i] - 'a'] == 0)   --distinct;
                
                ++i;
            }
            
            ans += (j - i + 1);
            
            ++j;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
        //code here.
        long long int ansTillK = helper(s, k);
        long long int ansTillK_1 = helper(s, k - 1);
        
        return ansTillK - ansTillK_1;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends