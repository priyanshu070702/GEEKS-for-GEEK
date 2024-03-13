//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         vector<int>ans;
         map<int,vector<int>>mp;
         for(int i=0;i<mat.size();i++){
             for(int j=0;j<mat[0].size();j++){
                 mp[i+j].push_back(mat[i][j]);
             }
         }
         bool odd=0;
         for(auto it:mp){
             vector<int>temp=it.second;
             if(odd==0)reverse(temp.begin(),temp.end());
             for(auto get:temp)ans.push_back(get);
             odd=!odd;
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends