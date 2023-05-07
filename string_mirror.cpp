class Solution{
public:
    string stringMirror(string str){
        int n=str.length();
        string st="";
        st+=str[0];
        for(int i=1;i<n;i++){
            if(str[i]<=str[i-1] && str[i]<str[0]){
                st+=str[i];
            }
            else break;
        }
        string rev=st;
        reverse(st.begin(),st.end());
        return rev+st;
    }
};
