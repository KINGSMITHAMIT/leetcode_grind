
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set(banned.begin(), banned.end());
        int sum = 0;
        int count = 0;
        
        // We can optimize by checking the condition in the loop more efficiently.
        for (int i = 1; i <= n && sum + i <= maxSum; i++) {
            if (set.find(i) != set.end()) continue;
            sum += i;
            count++;
        }

        return count;
    }
};
