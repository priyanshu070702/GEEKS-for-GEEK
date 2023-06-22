//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        //using map;
        map<int,int>mp;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                mp[bills[i]]++;
            }
            else{
                int rem_amount=bills[i]-5;
                if(rem_amount==5){
                    if(mp[5]>0){
                        mp[5]--;
                        mp[10]++;
                    }
                    else {return false;}
                }
                else if(rem_amount==15){
                    if(mp[5]>0 && mp[10]>0){
                        mp[5]--;
                        mp[10]--;
                        mp[20]++;
                    }
                    else if(mp[5]>=3){
                        mp[5]-=3;
                    }
                    else {return false;}
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends