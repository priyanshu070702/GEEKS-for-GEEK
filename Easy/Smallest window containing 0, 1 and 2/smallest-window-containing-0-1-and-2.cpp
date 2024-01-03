//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int n=s.size();
        int zeroCount=0;
        int oneCount=0;
        int twoCount=0;
        int size=INT_MAX;
        int i=0;
        int j=0;
        while(j<n){
          if(s[j]=='0'){
              zeroCount++;
          }
          else if(s[j]=='1'){
              oneCount++;
          }
          else if(s[j]=='2'){
              twoCount++;
          }
          if(zeroCount>=1 and oneCount>=1 and 
          twoCount>=1){
            while(zeroCount>=1 and oneCount>=1 and 
          twoCount>=1){
              size=min(size,j-i+1);
              if(s[i]=='0'){
                  zeroCount--;
              }
              else if(s[i]=='1'){
                  oneCount--;
              }
              else if(s[i]=='2'){
                  twoCount--;
              }
              i++;
            }
          }
          j++;
        }
    if(size==INT_MAX) return -1;
    return size;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends