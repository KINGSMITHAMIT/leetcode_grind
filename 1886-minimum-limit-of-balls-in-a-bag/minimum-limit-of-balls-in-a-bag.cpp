class Solution {
public:
    
bool canAchievePenalty(const std::vector<int>& nums, int maxOperations, int penalty) {
    int operations = 0;
    for (int balls : nums) {
        if (balls > penalty) {
            operations += (balls - 1) / penalty; // Number of operations needed to reduce the bag to size <= penalty
        }
        if (operations > maxOperations) {
            return false;
        }
    }
    return true;
}

int minimumSize(std::vector<int>& nums, int maxOperations) {
    int left = 1, right = *std::max_element(nums.begin(), nums.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAchievePenalty(nums, maxOperations, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}


    
};