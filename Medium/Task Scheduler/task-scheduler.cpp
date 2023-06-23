//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int ans=N;
        map<char,int>mp;
        int idle_count=0;
        int max_count=0;
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
            max_count=max(max_count,mp[tasks[i]]);
        }
           idle_count=(max_count-1)*K+(max_count-1);
      
        for(auto it:mp)
        {
          idle_count-=min(max_count-1,it.second);
    
        }
       return (idle_count>0)?(ans+idle_count):(ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends