class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff= -1, diff= 0;
       for(int i =0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            diff= nums[j]-nums[i];
            maxDiff=max(maxDiff, diff);
        }
       } 
       if(maxDiff==0) return -1;
       else
       return maxDiff;
    }
};