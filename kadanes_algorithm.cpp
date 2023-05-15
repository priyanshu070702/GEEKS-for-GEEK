class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum=0;
        int B[n];
        long long submax=INT_MIN;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            submax=max(sum,submax);
            if(sum<0){
                sum=0;
            }
        }
        return submax;
        
    
    }
};
