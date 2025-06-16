class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //brute force
    //     int maxDiff= -1, diff= 0;
    //    for(int i =0; i<nums.size(); i++){
    //     for(int j=i+1; j<nums.size(); j++){
    //         diff= nums[j]-nums[i];
    //         maxDiff=max(maxDiff, diff);
    //     }
    //    } 
    //    if(maxDiff==0) return -1;
    //    else return maxDiff;
        //optimal approach - two pointer

        int minEle = nums[0], maxDiff= 0, diff;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>minEle)  {
                diff = nums[i]  - minEle;
                maxDiff= max(maxDiff, diff);
            }
            else minEle= nums[i];   // if i never get any number bigger than the previous num then i won't be able to update the maxDiff 
        }
        if(maxDiff == 0)    return -1;
        else    return maxDiff;
    }
};