//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int numberOfEnclaves(vector<vector<int>> &grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     queue<pair<int,int>>q;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i==0||j==0||i==n-1||j==m-1){
    //                 if(grid[i][j]==1){
    //                     q.push({i,j});
    //                     vis[i][j]=1;
    //                 }
    //             }
    //         }
    //     }
    //     int dx[4]={-1,1,0,0};
    //     int dy[4]={0,0,1,-1};
    //     while(!q.empty()){
    //         auto front=q.front();
    //         q.pop();
    //         int x=front.first;
    //         int y=front.second;
    //         for(int i=0;i<4;i++){
    //             int xx=x+dx[i];
    //             int yy=y+dy[i];
    //             if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==1){
    //                 vis[xx][yy]=1;
    //                 q.push({xx,yy});
    //             }
    //         }
    //     }
        
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==1 && vis[i][j]==0)cnt++;
    //         }
    //     }
    //     return cnt;
    // }
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; // Handle empty grid
        int m = grid[0].size();
        if (m == 0) return 0; // Handle empty rows
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        // Start by marking land cells on the boundary
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        // Perform a BFS to mark land cells connected to the boundary
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1 && vis[xx][yy] == 0) {
                    vis[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
        
        // Count land cells that are not connected to the boundary
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends