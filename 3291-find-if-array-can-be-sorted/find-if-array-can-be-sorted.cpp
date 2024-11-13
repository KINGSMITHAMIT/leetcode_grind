#include<bit>
class Solution {
public:
int countSetBits(unsigned int num) { 
    int count = 0; 
    while (num) {
        count += num & 1; 
        num >>= 1; 
        } 
        return count; 
        }
    bool canSortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = 1; j < nums.size(); j++) {
                if(countSetBits(nums[j - 1]) == countSetBits(nums[j]) && nums[j - 1] > nums[j])
                    swap(nums[j - 1], nums[j]);
            }
        }
        if(is_sorted(nums.begin(), nums.end())) 
            return true;
        else 
            return false;
    }
};

