class Solution {
public:
    vector<vector<int>>ans;
    void combinationSum(vector<int> &candidates, int n, int target, vector<int>&v, int sum, int i){
        if(sum == target){
            ans.push_back(v);
            return;
        } 
        else if(sum>target||i>=n) return;

        v.push_back(candidates[i]);
        combinationSum(candidates, n, target, v, sum+candidates[i], i);
        v.pop_back();
        
        combinationSum(candidates, n, target, v, sum, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int>v;
        combinationSum(candidates, n, target, v, sum, 0);
        return ans;
    }
};