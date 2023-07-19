//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        //using bfs
        int n=grid.size();
        int m=grid[0].size();
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    grid[i][j]='0';
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto front=q.front();
                        q.pop();
                        for(int i=0;i<8;i++){
                            int dir_x=front.first+x[i];
                            int dir_y=front.second+y[i];
                            if(dir_x>=0 && dir_x<n && dir_y>=0 && dir_y<m && grid[dir_x][dir_y]=='1'){
                                grid[dir_x][dir_y]='0';
                                q.push({dir_x,dir_y});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends