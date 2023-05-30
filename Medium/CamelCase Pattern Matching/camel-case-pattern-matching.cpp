//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        int cnt=0;
        vector<string>store;
        vector<string>store0;
        store0.push_back("-1");
        for(int i=0;i<Dictionary.size();i++){
            string s=Dictionary[i];
            int k=0;
            cnt=0;
            for(int j=0;j<s.length();j++){
                if((s[j]>='A' && s[j]<='Z')){
                    if(Pattern[k]==s[j]){
                        cnt++;
                        if(cnt==Pattern.length()){
                          store.push_back(s);
                          break;
                        }
                      k++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(store.size()>0)return store;
        return store0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends