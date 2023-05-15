class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        //sort(array.begin(),array.end());
        int s=(n*(n+1)/2);
        int sum=0;
        for(int i=0;i<n-1;i++){
              sum=sum+array[i];
            }
            return s-sum;
        }
        
    
};
