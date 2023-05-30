//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool func(vector<vector<char>>&s, string w, int i, int j, int ind){
        if(ind==w.size())return true;
        if(i<0||j<0||i>=s.size()||j>=s[0].size()||s[i][j]!=w[ind])return false;
        char temp=s[i][j];
        s[i][j]='0';
        bool a=func(s,w,i+1,j,ind+1);
        bool b=func(s,w,i-1,j,ind+1);
        bool c=func(s,w,i,j+1,ind+1);
        bool d=func(s,w,i,j-1,ind+1);
        s[i][j]=temp;
        return (a||b||c||d);
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && func(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends