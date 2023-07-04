//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        //brute force
        //I can find out every possible subarray and check for every subarray if 
        //there product is less than the given number and if it is we will increse the 
        //count O(n*n)
        
        //optimized approach
        int ans=0;
        long long pro=1;
        int j=0;
        for(int i=0;i<n;i++){
            pro=pro*a[i];
            while(pro>=k && j<n){
                pro/=a[j];
                j++;
            }
            if(pro<k)
              ans+=(i-j+1);
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
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends