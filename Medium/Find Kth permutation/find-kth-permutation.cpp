//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        int factorial[11] ;
        factorial[0] = 1 ;
        string Ar = "", ans = "" ;
        
        for(int i = 1 ; i <= n ; i++)
        {
            factorial[i] = factorial[i - 1] * i ;
            Ar += '0' + i ;
        }
        
        for(int j = n ; j > 0 ; j--)
        {
            int i = 1 ;
            
            for( ; i <= n ; i++)
                if(k <= (i) * factorial[j - 1])
                {
                    ans += Ar[i - 1] ;
                    break ;
                }
            
            Ar.erase(Ar.begin() + i - 1) ;
            k = k - (i - 1) * factorial[j - 1] ;
            
        }
        
        return ans ;
    }


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends