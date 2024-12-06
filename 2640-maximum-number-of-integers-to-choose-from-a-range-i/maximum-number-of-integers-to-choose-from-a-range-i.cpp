#include <vector>
#include <unordered_set>

class Solution {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::vector<bool> set(10001, false);
        for (int ban : banned) {
            set[ban] = true;
        }

        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (set[i] == true) continue;
            sum += i;
            if (sum > maxSum) break;
            count++;
        }

        return count;
    }
};
