// class Solution {
// public:
//     vector<vector<int>>ans;
//     void combinationSum(vector<int> &candidates, int n, int target, vector<int>&v, int &sum, int i){
//         if(sum == target){
//             ans.push_back(v);
//             return;
//         } 
//         else if(sum>target||i>n) {
//             return;
//             }
//         v.push_back(candidates[i]);
//         sum+=candidates[i];
//         combinationSum(candidates, n, target, v, sum, i);
//         v.pop_back();
//         sum-=candidates[i];
//         combinationSum(candidates, n, target, v, sum, i+1);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int n = candidates.size();
//         int sum = 0;
//         vector<int>v;
//         combinationSum(candidates, n, target, v, sum, 0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(candidates, target, 0, 0, current, ans);
        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int sum, int index,
                   vector<int>& current, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        if (sum > target || index >= candidates.size()) {
            return;
        }

        // Include current candidate
        current.push_back(candidates[index]);
        backtrack(candidates, target, sum + candidates[index], index, current, ans);
        current.pop_back();

        // Exclude current candidate and move to next
        backtrack(candidates, target, sum, index + 1, current, ans);
    }
};