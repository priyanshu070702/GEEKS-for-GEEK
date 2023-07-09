//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        //brute force
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(arr[i]>0)mp[arr[i]]++;
        }
        int value=1;
        for(int i=0;i<mp.size();i++){
            if(mp.find(value)==mp.end())return value;
            else if(mp.find(value)!=mp.end())value++;
        }
        return value;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends