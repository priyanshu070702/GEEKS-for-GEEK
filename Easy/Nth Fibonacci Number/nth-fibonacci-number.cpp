//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
    int nthFibonacci(int n){
         int last = 1, secondLast=1, nth = 0, mod= 1000000007;
        if(n==1){
            return last;
        }else if(n==2){
            return secondLast;
        }else{
            while(n>2){
                nth = last%mod + secondLast%mod;
                last = secondLast;
                secondLast = nth;
                n--;
            }
            return nth%mod;
        }
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends