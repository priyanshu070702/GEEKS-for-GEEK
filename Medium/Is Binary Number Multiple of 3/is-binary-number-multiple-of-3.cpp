//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	   // int num=0;
	   // int sq=0;
	   // long long i=s.length()-1;
	   // while(i>=0){
	   //     int st=s[i]-'0';
	   //     num+=(st*pow(2,sq))%1e9+7;
	   //     i--;
	   //     sq++;
	   // }
	   // if(num%3==0)return 1;
	   // return 0;int n = s.size();

long long int sum=0;

for(int i=0;i<s.length();i++){

sum = (sum*2+s[i]-'0')%3;

}      

if(sum%3==0) return 1;

else return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends