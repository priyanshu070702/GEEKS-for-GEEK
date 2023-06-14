//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void func(vector<int>&A, vector<vector<int>>&ans, vector<int>st, int i){
        //base condition
        if(i>=A.size()){
            ans.push_back(st);
            return;
        }
        //exclude
        func(A,ans,st,i+1);
        
        //include
        int ele=A[i];
        st.push_back(ele);
        func(A,ans,st,i+1);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>>ans;
        vector<int>st;
        int ind=0;
        func(A,ans,st,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends