int is_power_of_5(string s){
        int n=s.length(), number=0;
        if(!n) return 0;
        
        if(s[0]=='0' || s[n-1]=='0') return 0;
        if(n==1 && s[0]=='1') return 1;
        
        
        for(int i=0;i<n;i++){
            number+=pow(2, i)*(s[n-1-i]-'0');
        }
        
        while(number%5==0) number/=5;
        if(number==1) return 1; else return 0;
    }
    
    int cuts(string s){
        
        for(int i=0;i<s.length();i++){
            if(is_power_of_5(s.substr(i, s.length()-i))) {
                //check for the remaining string
                if(i==0) return 1;
                int left=cuts(s.substr(0, i));
                if(left!=-1) return (1+left);
            }
        }
        return -1;
    }
