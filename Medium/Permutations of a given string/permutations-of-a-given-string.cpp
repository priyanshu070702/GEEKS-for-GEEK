//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void func(string s, set<string>&st, int i){
	        if(i>=s.length()){
	            st.insert(s);
	            return;
	        }
	        for(int j=i;j<s.length();j++){
	            
	                swap(s[j],s[i]);
	                func(s,st,i+1);
	                swap(s[i],s[j]);
	            
	    }}
		vector<string>find_permutation(string S)
		{
		    set<string>st;
		    int i=0;
		    func(S,st,i);
		    vector<string>res(st.begin(),st.end());
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
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends