//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    
    int sumOfDigit(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int primeFactors(int num) {
        int count = 0, d = 2, primeOrNot = 0;
    
        while(num > 1) {
            if(num%d == 0) {
                count += sumOfDigit(d);
                primeOrNot++;
                num /= d;
            }
            else{
                d++;
            }
        }
        
        if(primeOrNot == 1) return -1;
        
        return count;
    }
    
  public:
    int smithNum(int n) {
        
        if(primeFactors(n) == sumOfDigit(n)) {
            return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends