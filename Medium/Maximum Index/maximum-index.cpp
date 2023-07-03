//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
       //brute force --> sort the arrar, then from back try all pairs combination then
       //iterate in the main array and check for index and check for maximum index vale
       //O(n*n)
       
       //optimized
       
       int mx[n];
       mx[n-1]=arr[n-1];
       for(int i=n-2;i>=0;i--){
           mx[i]=max(mx[i+1],arr[i]);
       }
       int i=0,j=0;
       int ans=INT_MIN;
       
       while(i<n && j<n){
           if(arr[i]<=mx[j]){
               ans=max(ans,j-i);
               j++;
           }
           else i++;
       }
       return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends