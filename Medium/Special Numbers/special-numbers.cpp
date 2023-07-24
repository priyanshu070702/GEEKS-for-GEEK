//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
    
public:
    bool func(int n){
        if(n==0)return true;
        while(n!=0){
            int rem=n%10;
            if(rem==0 ||rem==1 ||rem==2 ||rem==3 ||rem==4 || rem==5)return true;
            n=n/10;
        }
        return false;
    }
    int getSpecialNumber(int N){
        N--;
        int x=1,ans=0;
        while(N){
            ans = x*(N%6) + ans;
            N/=6;
            x*=10;
        }
        return ans;
    }

};



//{ Driver Code Starts.

int main() 
{
	int t;
	cin>>t;
	while(t-->0)
	{
	    int N;
	    cin>> N;
	     Solution ob;
	    cout<<ob.getSpecialNumber(N)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends