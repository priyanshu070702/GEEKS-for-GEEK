//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool issafe(int i, int j, int n ,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }
    int Count(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int cnt_even=0;
                if(matrix[i][j]==1){
                    for(int k=0;k<8;k++){
                        int r=i+dx[k];
                        int c=j+dy[k];
                        if(issafe(r,c,n,m)==1 && matrix[r][c]==0){
                            cnt_even++;
                        }
                    }
                    if(cnt_even%2==0 && cnt_even!=0)cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends