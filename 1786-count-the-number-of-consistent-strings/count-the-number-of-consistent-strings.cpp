class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        set<int> allow(allowed.begin(), allowed.end());
        for (int i = 0; i < words.size(); i++) {
            int fnd = 1;
            for (int j = 0; j < words[i].size(); j++) {
                if (allow.find(words[i][j]) == allow.end()) {
                    fnd = 0;
                    break;
                }
            }
            if (fnd) {
                cnt++;
            }
        }
        return cnt;
    }
};
