//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>v;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                v.push_back(i);
                break;
            }
            if(i==n-1)v.push_back(-1);
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                v.push_back(i);
                break;
            }
            if(i==0)v.push_back(-1);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends