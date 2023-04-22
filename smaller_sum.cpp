vector<long long> smallerSum(int n,vector<int> &arr){
        //brute force approach
    //    long long ans=0;
    //     vector<long long>v;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(arr[j]<arr[i]){
    //                 ans=ans+arr[j];
    //             }
    //         }
    //         v.push_back(ans);
    //         ans=0;
    //     }
    // return v;
         
         //optimized approach
        //  
        // vector<int>v(arr.begin(),arr.end());
        // sort(v.begin(),v.end());
        // unordered_map<long long,long long>mp;
        // long long sum=0;
        // for(int i=0;i<n;i++) {
        //     mp.insert({v[i],sum});
        //     sum+=v[i];
        // }
        // vector<long long>ans;
        // for(int i=0;i<n;i++) ans.push_back(mp[arr[i]]);
        // return ans;
        
        vector<int>copy=arr;
         
        sort(copy.begin(),copy.end()); // sort elements
        
        long long sum=0;
        vector<long long>ans;
        
         
        long long prefixsum=0;  //creating prefix sum to calcilate values in binary search
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            mp[i]=prefixsum;
            prefixsum+=copy[i];
        }
         
        for(int i=0;i<n;i++){ 
            int ele=arr[i];
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(copy[mid]>=ele){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
                
             }
             ans.push_back(mp[low]);
         }
         return ans;
    }
};
