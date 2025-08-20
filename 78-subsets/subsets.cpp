class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int> &nums, vector<int>subset, int i , int n){
        if(i>=n){
            st.insert(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(nums, subset, i+1,n);
        subset.pop_back(); // backtrack logic
        //new subset
        helper(nums, subset, i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        helper(nums, subset, 0, n);
        vector<vector<int>> ans;
        for( auto &it : st) ans.push_back(it);
        return ans; 
    }
};