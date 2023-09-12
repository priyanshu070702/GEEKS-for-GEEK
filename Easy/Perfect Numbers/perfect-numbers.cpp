//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N==1)return 0;
        long long int n=pow(N,0.5);
        long long int cnt=1;
        for(int i=2;i<=n;i++){
            if(N%i==0)
            cnt+=(i +( N/i ));
        }
        if(N==cnt)return 1;
        else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends