//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S==0&&N>1){
            return "-1";
        }
        string res="";
        while(res.size()<N&&S>0){
            if(S<10){
                res+='0'+S;
                S=0;
            }
            else{
                res+='9';
                S-=9;
            }
        }
        while(res.size()<N){
            res+='0';
        }
        if(S!=0){
            return "-1";
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends