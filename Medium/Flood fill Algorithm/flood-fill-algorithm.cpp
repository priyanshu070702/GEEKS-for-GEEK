//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solveBFS(vector<vector<int>>&image, int i, int j, int n, vector<vector<bool>>&vis, int getColor){
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        image[i][j]=n;
        while(!q.empty()){
            auto x=q.front().first;
            auto y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<image.size() && new_y>=0 && new_y<image[0].size() && image[new_x][new_y]==getColor && vis[new_x][new_y]==0){
                    vis[new_x][new_y]=1;
                    image[new_x][new_y]=n;
                    q.push({new_x,new_y});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size(),0));
        int getColor=image[sr][sc];
        solveBFS(image,sr,sc,newColor,vis,getColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends