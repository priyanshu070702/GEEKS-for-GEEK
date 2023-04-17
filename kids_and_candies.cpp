class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=INT_MIN;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>mx){
                mx=candies[i];
            }
        }
        vector<bool>res;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=mx)res.push_back(1);
            else res.push_back(0);
        }
        return res;
    }
};
