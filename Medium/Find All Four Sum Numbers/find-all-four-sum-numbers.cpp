//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j=i+1;j<n-2;j++){
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                vector<int>v;
                int e1=arr[i],e2=arr[j];
                v.push_back(e1);
                v.push_back(e2);
                int low=j+1;
                int high=n-1;
                while(low<high){
                    if (low > j+ 1 && arr[low] == arr[low - 1]) { 
                        low++;
                        continue;
                    }
                    if (high < n-1 && arr[high] == arr[high+1]) {
                        high--;
                        continue;
                    }
                    if(e1+e2+arr[low]+arr[high]==K){
                        v.push_back(arr[low]);
                        v.push_back(arr[high]);
                        ans.push_back(v);
                        v.pop_back();
                        v.pop_back();
                        low++;
                        high--;
                    }
                    else if(e1+e2+arr[low]+arr[high]<K){
                        low++;
                    }
                    else high--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends