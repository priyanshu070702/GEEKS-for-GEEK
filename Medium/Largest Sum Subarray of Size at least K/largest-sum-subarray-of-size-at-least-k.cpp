//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long ksum = 0;
        for (int i = 0; i < k; i++)
            ksum += a[i];

        long long maxsum = ksum;
        long long sum = ksum;

        for (int i = k; i < n; i++) {
            ksum = ksum + a[i] - a[i - k];
            sum = max(sum + a[i], ksum);
            maxsum = max(sum, maxsum);
        }

        return maxsum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends