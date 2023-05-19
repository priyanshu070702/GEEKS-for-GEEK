//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
     void dfs(vector<vector<int>>& matrix,int i,int j,int N,int M){
        matrix[i][j]=0;
        int dx[4]={0,0,-1,1};   //R L U D
        int dy[4]={1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 &&  x<N  &&  y>=0  && y<M && matrix[x][y]==1){
                dfs(matrix,x,y,N,M);
            }
            
        }
        
        
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]==1){
                    if(j*i==0 || i==N-1 || j==M-1 )
                    {
                        dfs(matrix,i,j,N,M);
                    }
                }
            }
        }
     int   cnt=0;
     
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]==1)
                {
                   cnt++;
                   dfs(matrix,i,j,N,M);
                }
                }
            }
         
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends