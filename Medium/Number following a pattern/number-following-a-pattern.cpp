//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans="";
        int n = S.size();
        stack<int> st;
        int cnt=1;
        for(int i = 0; i <n; i++)
        {
            st.push(cnt);
            cnt++;
            if(S[i] == 'I')
            {
                while(st.size())
                {
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(cnt);
        cnt++;
        while(st.size())
        {
            ans+=to_string(st.top());
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends