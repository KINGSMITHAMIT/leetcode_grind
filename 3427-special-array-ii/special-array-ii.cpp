class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> count(n, 0);
        
        for(int i = 1; i < n; i++) {
            int parity = (nums[i] % 2 == nums[i - 1] % 2) ? 1 : 0;
            count[i] = count[i - 1] + parity;
        }

        int m = queries.size();
        vector<bool> res(m);

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            res[i] = (count[end] - count[start] == 0);
        }

        return res;
    }
};
