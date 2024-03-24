//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void generateString(int n,vector<string>& values,string cur,int k) {
        if(cur.size()==n) {
            if(k>=0) values.push_back(cur);
            return;
        }
        generateString(n,values,cur+'1',k+1);
        if(k>0) generateString(n,values,cur+'0',k-1);
    }
	vector<string> NBitBinary(int n){
	    vector<string> values;
	    string cur = "1";
	    generateString(n,values,cur,1);
	    return values;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends