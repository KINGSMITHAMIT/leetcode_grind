class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest = INT_MAX, largest = INT_MIN;
        vector<int>v(101,0);
        for(int i = 0; i<nums.size(); i++){
            smallest = min(nums[i], smallest);
            largest = max(nums[i], largest);
            v[nums[i]]++;
        }
        vector<int>ans;
        for(int i = smallest; i<=largest; i++){
            if(v[i]==0) ans.push_back(i);
        }
        return ans;
    }
};