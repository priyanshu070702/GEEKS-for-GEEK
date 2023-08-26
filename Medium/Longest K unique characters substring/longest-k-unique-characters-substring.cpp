//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        //O(n*n)
    //  set<int>st;
    //  int mx=-1;
    //  for(int i=0;i<s.length();i++){
    //      for(int j=i;j<s.length();j++){
    //          st.insert(s[j]);
    //          if(st.size()==k){
    //              mx=max(mx,j-i+1);
    //          }
    //          else if(st.size()>k)break;
    //      }
    //      st.clear();
    //  }
    //  return mx;
    
    //O(n)
    unordered_map<char,int>mp;
    int j=0,i=0,mx=-1;
    while(i<s.length()){
        mp[s[i]]++;
        if(mp.size()==k){
            mx=max(mx,i-j+1);
        }
        if(mp.size()>k){
            mp[s[j]]--;
            if(mp[s[j]]==0)mp.erase(s[j]);
            j++;
        }
        i++;
    }
    return mx;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends