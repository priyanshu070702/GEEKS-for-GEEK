//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int i=1,j=N;
        //stack<int>st;
        int a = 1;
        while(i<j){
            for(int x=0; x<K;x++){
                //st.push(a++);
                i++;
                if(i==j)break;
            }
            for(int y=0;y<K;y++){
                //st.push(N--);
                j--;
                if(i==j)break;
            }
        }
        return i;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends