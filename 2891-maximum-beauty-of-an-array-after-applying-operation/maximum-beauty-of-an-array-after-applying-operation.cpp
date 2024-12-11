class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        auto maxIT = max_element(nums.begin(), nums.end());
        vector<int> arr(*maxIT + 2, 0); // Increase the size by 1 to safely access e+1
        
        for (int i = 0; i < nums.size(); i++) {
            int s = nums[i] - k;
            if (s < 0) arr[0]++;
            else arr[s]++;
            
            int e = nums[i] + k;
            if (e + 1 >= arr.size()) arr.back()--;
            else arr[e + 1]--;
        }

        int c_sum = 0;
        int m_sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            c_sum += arr[i];
            m_sum = max(m_sum, c_sum);
        }
        return m_sum;
    }
};
