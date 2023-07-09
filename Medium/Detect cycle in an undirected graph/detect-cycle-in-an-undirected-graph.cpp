//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool BFS(vector<int>adj[], vector<bool>&vis, int i){
        unordered_map<int,int>parent;
        vis[i]=true;
        parent[i]=-1;
        
        queue<int>q;
        q.push(i);
        
        while(!q.empty()){
            auto frontNode=q.front();
            q.pop();
        
        for(auto it:adj[frontNode]){
            if(vis[it]==false){
                q.push(it);
                vis[it]=true;
                parent[it]=frontNode;
            }
            else if(vis[it]==true && it!=parent[frontNode]){
                return true;
            }
        }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false)
                if(BFS(adj,vis,i)==1)return true;
        }
        return false;
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