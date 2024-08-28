class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        bool flag = false;
        int idx;
        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]== target) {
                flag = true;
                idx= mid;
                break;
            }
            else if(nums[mid]>target ) hi =mid-1;
            else lo = mid+1;
           }
           if (flag == true ) return idx;
           else return lo;
    }
};