// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs) {
//         map<int, int>mp;
//         for(int i = 0; i<logs.size(); i++){
//             mp[logs[i][0]]++;
//             mp[logs[i][1]]--;
//         }
        
//         int ans=INT_MIN;
//         for(const auto &it: mp){
//             if(it.second>ans)ans=it.first;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp; // Difference array in map form

        // Marking births and deaths
        for(const auto& log : logs) {
            mp[log[0]]++;  // Birth year increment
            mp[log[1]]--;  // Death year decrement
        }

        int maxPop = 0, currPop = 0, bestYear = INT_MAX;
        
        // Compute running population count
        for(const auto& year : mp) {
            currPop += year.second;
            
            // If new max found, update
            if (currPop > maxPop) {
                maxPop = currPop;
                bestYear = year.first;
            }
        }

        return bestYear;
    }
};

