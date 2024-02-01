//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool isAlpha(char c){
        if((c>='a' && c<='z')||(c>='A' && c<='Z'))return 1;
        return 0;
    }
    bool checkPangram (string s) {
        vector<int>alpha(26,0);
        for(int i=0;i<s.length();i++){
            if(isAlpha(s[i])){
                if(s[i]-'a'>=0)alpha[s[i]-'a']=1;
                else alpha[tolower(s[i])-'a']=1;
            }
        }
        for(int i=0;i<26;i++){
            if(alpha[i]==0)return 0;
        }
        return 1;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends