//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        if(K>N)return 0;
        long mx=0,sum=0;
        for(int i=0;i<K;i++){
            sum+=Arr[i];
        }
        int j=0;
        mx=max(mx,sum);
        for(int i=K;i<N;i++){
            sum-=Arr[j++];
            sum+=Arr[i];
            mx=max(mx,sum);
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends