class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int l = nums.size();
        int n = 2 * l;
        vector<int> ans(n); // Create a vector to hold the concatenated elements

        // Copy the elements from the first array
        for (int i = 0; i < l; i++)
            ans[i] = nums[i];

        // Copy the elements from the second array
        for (int i = 0; i < l; i++)
            ans[i + l] = nums[i];

        return ans;
    }
};
