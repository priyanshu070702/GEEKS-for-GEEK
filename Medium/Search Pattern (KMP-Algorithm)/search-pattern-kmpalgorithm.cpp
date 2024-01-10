//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            // int n=txt.length();
            // int m=pat.length();
            // vector<int>ans;
            // for(int i=0;i<=n-m;i++){
            //     if(txt.substr(i,m)==pat)ans.push_back(i+1);
            // }
            // return ans;
             vector<int> v;
            for(int i = 0;i< txt.length();i++){
                int start = 0;
                int c = i;
                while(start != pat.length() && txt[c] == pat[start]){
                    c++;
                    start++;
                }
                if( start == pat.length()){
                    v.push_back(i+1);
                }
            }
            return v;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends