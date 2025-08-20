class Solution {
public:
    vector<vector<int>>ans;
    void sub(vector<int>&nums, vector<int>&subset, int i , int n ){
        if(i>=n){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        sub(nums, subset, i+1, n);
        subset.pop_back();// backtracking to prevent the passage of same subset in the empty line
        sub(nums, subset, i+1, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        sub(nums, subset, 0, n);
        return ans;
    }
};