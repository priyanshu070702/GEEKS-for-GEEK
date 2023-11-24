//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<vector<long long> >v(n,vector<long long>(n,0));
        int mod=1e9+7;
        for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            if(i==j || j==0){
            v[i][j]=1;
            }
            else
            if(i-1<0 || j-1<0){
            v[i][j]=v[i][j];
            }
            else
            v[i][j]=(v[i-1][j]+v[i-1][j-1])%mod;
         }
        }
        vector<long long>ans;
       for(int i=0;i<n;i++){
        ans.push_back(v[n-1][i]);
       }
       return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends