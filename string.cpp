class Solution{
    public:
    bool wifiRange(int n, string s, int x){
         int back=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            back++;
            else{
                if(back>x)
                return 0;
                back = -x;
            }
        }
        if(back>0)
        return 0;
        return 1;
    }
};
