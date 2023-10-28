//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
     int countbit(int n){
        int count = 0;
       while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
        
        
    }
    int is_bleak(int n)
    {
        if(n>32){
       for(int x = n-32; x<=n; x++){
           
           
           if(x + countbit(x)== n)
           return 0;
       }
        }
        else{
       for(int i = 1; i<n; i++){
           
           
           if(i + countbit(i)== n)
           return 0;
       }
       
        }
        return 1;
       
       
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends