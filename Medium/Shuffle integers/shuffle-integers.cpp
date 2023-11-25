//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	   vector<int>temp1,temp2;
        for(int i=0;i<n/2;i++)
        {
            temp1.push_back(arr[i]);
        }
        for(int i=n/2;i<n;i++)
        {
            temp2.push_back(arr[i]);
        }
        int i=0,j=0,k=0;
        while(i<temp1.size() && j<temp2.size())
        {
            arr[k]=temp1[i];
            k++;i++;
            arr[k]=temp2[j];
            k++;j++;
        }
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends