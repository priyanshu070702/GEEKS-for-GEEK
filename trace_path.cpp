class Solution{
public:
    int isPossible(int n, int m, string s){
        int row=0,col=0,minn=0,maxn=0,minm=0,maxm=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='R'){
                col++;
                maxm=max(maxm,col);
            }
            else if(c=='L'){
                col--;
                minm=min(minm,col);
            }
            else if(c=='U'){
                row++;
                maxn=max(maxn,row);
            }
            else if(c=='D'){
                row--;
                minn=min(minn,row);
            }
        }
        if(maxm-minm>=m || maxn-minn>=n)return 0;
        return 1;
    }
};
