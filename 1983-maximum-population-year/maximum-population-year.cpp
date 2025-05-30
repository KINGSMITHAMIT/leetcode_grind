class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int>mp;
        for(int i = 0; i<logs.size(); i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }
        
        int maxPop=INT_MIN,currPop=INT_MIN, ans; 
        for(const auto &it: mp){
            currPop+=it.second;
            if(currPop>maxPop){
                maxPop= currPop;
                ans=it.first;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs) {
//         map<int, int> mp;

//            for(const auto& log : logs) {
//             mp[log[0]]++;  
//             mp[log[1]]--;  
//         }

//         int maxPop = 0, currPop = 0, bestYear = INT_MAX;
        
        
//         for(const auto& year : mp) {
//             currPop += year.second;
            
//             if (currPop > maxPop) {
//                 maxPop = currPop;
//                 bestYear = year.first;
//             }
//         }

//         return bestYear;
//     }
// };

