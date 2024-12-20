#include <queue>
#include <string>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant;
        std::queue<int> dire;
        int n = senate.size();

        // Populate the queues with the indices of R and D
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Process the ban round
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();
            radiant.pop();
            dire.pop();

            if (rIndex < dIndex) {
                radiant.push(rIndex + n);
            } else {
                dire.push(dIndex + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
