//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int happy(int x){
        if(x==1 || x==7)return 1;
        int res=x,sum=x;
        while(sum>9){
            sum=0;
            while(res>0){
                int d=res%10;
                sum+=d*d;
                res/=10;
            }
            if(sum==1){
                return 1; 
            }
            res=sum;
        }
        if(sum==7){
            return 1;
        }
        return 0;
    }
    int nextHappy(int N){
        int x=N+1;
        while(true){
            if(happy(x)==1){
                return x;
            }
            x++;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends