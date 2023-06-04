//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    bool exp(char c){
        if(c=='+'||c=='-'||c=='/'||c=='*')return 1;
        return 0;
    }
    string reverseEqn (string s){
        stack<string>st;
        string temp="";
        int i=0;
        while(i<s.length()){
            if(exp(s[i])==1){
                string str="";
                str+=s[i];
                st.push(str);
                i++;
            }
            else{
                while(exp(s[i])==0 && i<s.length()){
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
                temp="";
            }
        }temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        return temp;
        // string rev="";
        // string temp="";
        // int i =  s.length()-1;
        // while(i>=0){
        //     if(exp(s[i])==1){
        //         rev+=s[i];
        //         i--;
        //     }
        //     else{
        //         while(exp(s[i])==0 && i>=0){
        //             temp+=s[i];
        //             i--;
        //         }
        //         reverse(temp.begin(),temp.end());
        //         rev+=temp;
        //         temp="";
        //     }
        // }
        // return rev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends