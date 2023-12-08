//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    bool isPrime(int n){
        if(n<=1)return false;
        if(n==2)return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }
        return true;
    }
    
    int minNumber(int arr[],int N)
    {
        int sum=accumulate(arr,arr+N,0);
        for(int i=sum;i<=2*sum;i++){
            if(isPrime(i)){
                return i-sum;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends