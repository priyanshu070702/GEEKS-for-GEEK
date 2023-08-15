//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
         int one=0;
        for(int i=0;i<n;i++) if(a[i]==1) one++;
        int ans=INT_MIN;
        int j=0,c1=0,c2=0;
        while(j<n){
            if(a[j]==1) c1++;
            else c2++;
            if(c1>c2){
                c1=0,c2=0;
            }
            ans=max(ans,one-c1+c2);
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends