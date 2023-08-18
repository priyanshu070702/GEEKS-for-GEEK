//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int node, vector<bool>&vis, vector<int> adj[]){
        unordered_map<int,int>mp;
        queue<int>q;
        vis[node]=1;
        mp[node]=-1;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(vis[it]==0){
                    mp[it]=front;
                    vis[it]=1;
                    q.push(it);
                }
                else if(vis[it]==1 && it!=mp[front]){
                    return 1;
                } 
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans=isCyclic(i,vis,adj);
                if(ans==1)return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends