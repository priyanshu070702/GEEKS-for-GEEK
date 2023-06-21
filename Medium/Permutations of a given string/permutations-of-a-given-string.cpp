//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve_permu(string S,int i,vector<string>&res){
	        if(i>=S.length()){
	            res.push_back(S);
	            return;
	        }
	        for(int idx=i;idx<S.length();idx++){
	            swap(S[i],S[idx]);
	            solve_permu(S,i+1,res);
	            swap(S[i],S[idx]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>res;
		    solve_permu(S, 0, res);
		    sort(res.begin(),res.end());
		    res.erase(unique(res.begin(), res.end()), res.end());
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends