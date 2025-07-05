
class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> freq;

        // Count frequencies
        for (int n : arr) {
            freq[n]++;
        }

        int luckyInteger = -1;

        // Check for lucky integers
        for (const auto& [key, value] : freq) {
            if (key == value) {
                luckyInteger = std::max(luckyInteger, key);
            }
        }

        return luckyInteger;
    }
};