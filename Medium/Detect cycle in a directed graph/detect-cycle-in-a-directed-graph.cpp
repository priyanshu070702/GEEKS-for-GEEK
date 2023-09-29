//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycle(int idx, vector<bool>&vis, vector<bool>&dfsvis,vector<int> adj[]){
        vis[idx]=1;
        dfsvis[idx]=1;
        for(auto it:adj[idx]){
            if(vis[it]==1 && dfsvis[it]==1)return true;
            else if(vis[it]==0){
                bool val=isCycle(it,vis,dfsvis,adj);
                if(val==1)return true;
            }
        }
        dfsvis[idx]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        vector<bool>dfsvis(V,0);
        for(int i=0;i<V;i++){
            if(isCycle(i,vis,dfsvis,adj)==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends