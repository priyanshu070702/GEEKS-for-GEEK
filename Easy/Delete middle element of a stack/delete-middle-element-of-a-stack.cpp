//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        vector<int>ans;
        int mid=sizeOfStack/2;
        for(int i=sizeOfStack-1;i>=0;i--){
            int st=s.top();
            s.pop();
            if(sizeOfStack%2==0 && i==mid-1)continue;
            if(sizeOfStack%2!=0 && i==mid)continue;
            ans.push_back(st);
        }
        for(int i=ans.size()-1;i>=0;i--){
            s.push(ans[i]);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends