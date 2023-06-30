//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int i, int j, int n, vector<vector<int>>m,vector<vector<int>>&vis){
        if(i>=0 && i<n && j>=0 && j<n && vis[i][j]==0 && m[i][j]==1)return 1;
        return 0;
    }
    void ratrec(vector<vector<int>> &m,int n,int i,int j, vector<string>&ans, vector<vector<int>>&vis, string s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        //move down
        if(isSafe(i+1,j,n,m,vis)){
            s.push_back('D');
            ratrec(m,n,i+1,j,ans,vis,s);
            s.pop_back();
        }
        //move right
        if(isSafe(i,j+1,n,m,vis)){
            s.push_back('R');
            ratrec(m,n,i,j+1,ans,vis,s);
            s.pop_back();
        }
        //move up
        if(isSafe(i-1,j,n,m,vis)){
            s.push_back('U');
            ratrec(m,n,i-1,j,ans,vis,s);
            s.pop_back();
        }
        //move left
        if(isSafe(i,j-1,n,m,vis)){
            s.push_back('L');
            ratrec(m,n,i,j-1,ans,vis,s);
            s.pop_back();
        }
        vis[i][j]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string s="";
        vector<vector<int>>vis=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        if(m[0][0]==0 || m[n-1][n-1]==0)return ans;
        ratrec(m,n,0,0,ans,vis,s);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends