class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(const auto &it : nums)  cout<<it;
    }
};