//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//brute force approach
    // 	int sum=0;
    // 	for(int i=0;i<n-1;i++){
    // 	    for(int j=i+1;j<n;j++){
    // 	        int xoro=arr[i]^arr[j];
    // 	        sum+=xoro;
    // 	    }
    // 	}
    // 	return sum;
    
    //optimized approach
         long long sum = 0;
        
        for(int i = 0; i < 32; i++){
            
            long long set = 0, unset = 0, mask = (1 << i);
            
            for(int j = 0; j < n; j++){
                
                if(arr[j] & mask)   ++set;
                
                else    ++unset;
            }
            
            sum += (1LL << i) * (unset * set);
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends