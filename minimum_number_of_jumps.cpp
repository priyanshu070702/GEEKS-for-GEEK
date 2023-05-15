class Solution{
  public:
    int minJumps(int arr[], int n){
        int m=0,k=0,a=0;
        for(int i=0;i<n-1;i++){
            m=max(m,i+arr[i]);
            if(i==a){
                k++;
                a=m;
            }
            if(i>=m){
                return -1;
            }
        }
        return k;
    }
};
