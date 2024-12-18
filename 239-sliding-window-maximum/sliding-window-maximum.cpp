#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if(k == 1) return nums;
        
        std::deque<int> dq;
        std::vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(dq.front() == i - k) {
                dq.pop_front();
            }
            
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};
