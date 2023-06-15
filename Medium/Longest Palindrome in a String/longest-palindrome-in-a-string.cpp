//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   bool isPalindrome(string s){
//       int i=0,j=s.length()-1;
//       if(s.length()==1)return 1;
//       while(i<=j){
//           if(s[i]!=s[j]){
//               return 0;
//           }
//           i++;j--;
//       }
//       return 1;
//  }
    // string longestPalin (string S) {
    //     //optimized approach O(n*n);
    //     int n=S.size();
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     string s;
    //     int mx=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==j){
    //                 dp[i][j]=1;
    //             }
    //         }
    //     }
    //     for(int k=1;k<n;k++){
    //         for(int i=1,j=i+k;j<n;i++,j++){
    //             if(k==1){
    //                 if(s[i]==s[j]){
    //                     dp[i][j]=2;
    //                 }
    //                 else{
    //                     dp[i][j]=0;
    //                 }
    //             }
    //             else{
    //                 if(s[i]==s[j] && dp[i+1][j-1]>0){
    //                     dp[i][j]=dp[i+1][j-1]+2;
    //                 }
    //             }
    //             if(dp[i][j]>0){
    //                 if(j-i+1>mx){
    //                   mx=j-i+1;
    //                   s=S.substr(i,j-i+1);
    //                 }
    //             }
                
    //         }    
    //     }
    //     return s;
        
        
    //     //brute force approach O(n*n*n)
    //     // int mx=INT_MIN;
    //     // string st="";
    //     // string temp="";
    //     // for(int i=0;i<S.length();i++){
    //     //     string temp="";
    //     //     for(int j=i;j<S.length();j++){
    //     //         temp+=S[j];
    //     //         if(isPalindrome(temp)==1){
    //     //             if(temp.length()>mx){
    //     //                 mx=temp.length();
    //     //             }
    //     //         }
    //     //     }
    //     // }
    //     // return st;
    // }
    string longestPalin(string s) {
        int n=s.length();
        int mx=1;
        int start=0;
        for(int i=1;i<=n;i++){
            //Check for even string
            int l=i-1;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>mx){
                    mx=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            //Check for odd string
            l=i-1;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>mx){
                    mx=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,mx);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends