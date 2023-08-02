//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0 || A[X][Y]==0)return -1;
        if(X==0 && Y==0)return 0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(N,vector<bool>(M,0));
        int ans=INT_MAX;
        q.push({{0,0},0});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        vis[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int cnt=it.second;
            if(r==X && c==Y){
                ans=min(ans,cnt);
                vis[r][c]=0;
                continue;
            }
            for(int i=0;i<4;i++){
                int rr=r+dx[i];
                int cc=c+dy[i];
                if(rr>=0 && rr<N && cc>=0 && cc<M && A[rr][cc]==1 && vis[rr][cc]==0){
                    q.push({{rr,cc},cnt+1});
                    vis[rr][cc]=1;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends