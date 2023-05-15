    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
         vector<int>ans;
        int maax=INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=maax)
            {
                maax=a[i];
                ans.push_back(maax);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
