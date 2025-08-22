class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& nums, vector<int>&subset, int n , int i){
        if(i>=n){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(nums, subset, n, i+1);
        subset.pop_back();
        helper(nums, subset, n, i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>subset;
        helper(nums, subset, n , 0);
        return ans;
        
    }
};