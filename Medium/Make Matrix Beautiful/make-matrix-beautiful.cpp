//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int>st_row;
        vector<int>st_col;
        int mx=INT_MIN;
        
        for(int i=0;i<n;i++){
            int row_sum=0;
            for(int j=0;j<n;j++){
                row_sum+=matrix[i][j];
            }
            mx=max(mx,row_sum);
            st_row.push_back(row_sum);
        }
        
        for(int j=0;j<n;j++){
            int col_sum=0;
            for(int i=0;i<n;i++){
                col_sum+=matrix[i][j];
            }
            mx=max(mx,col_sum);
            st_col.push_back(col_sum);
        }
        
        int final_operations=0;
        
        for(int i=0;i<n;i++){
            final_operations+=abs(mx - st_col[i]);
        }
        
        return final_operations;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends