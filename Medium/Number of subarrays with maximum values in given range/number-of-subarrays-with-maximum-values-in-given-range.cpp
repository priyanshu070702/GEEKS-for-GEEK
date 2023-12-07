//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R){
        long ans=0;
        long cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]<=R){
                while(a[i]<=R && i<n){
                    cnt++;
                    i++;
                }
            }
            ans+=(cnt*(cnt+1))/2;
            if(a[i]>R)cnt=0;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]<L){
                while(a[i]<L && i<n){
                    cnt++;
                    i++;
                }
            }
            ans-=(cnt*(cnt+1))/2;
            if(a[i]>=L)cnt=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends