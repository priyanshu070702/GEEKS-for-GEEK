//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int mod=1e9+7;
	    ll zero=1;
	    ll one=1;
	    ll sum=2;
	    if(n==1)return sum;
	    ll i=2;
	    while(i<=n){
	        one=zero%mod;
	        zero=sum%mod;
	        sum=(one+zero)%mod;
	        i++;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends