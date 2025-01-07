class Solution {
public:
   bool isSubstring(const std::string& sub, const std::string& word) {
    int n = word.length();
    int m = sub.length();
    for (int j = 0; j < n; j++) {
        bool isMatch = true;
        int k = j;
        int i = 0;
        while (i < m) {
            if (k >= word.length() || word[k] != sub[i]) {
                isMatch = false;
                break;
            }
            k++;
            i++;
        }
        if (isMatch) {
            return true;
        }
    }
    return false;
}
    vector<string> stringMatching(vector<string>& s) {
        vector<string> res;
        for(int i = 0; i< s.size(); i++){
            for(int j = 0; j<s.size(); j++){
                if(s[i].size()>s[j].size()|| i ==j) continue;
                if(isSubstring(s[i],s[j])) {
                    res.push_back(s[i]);
                    break;
                }
            }
        }
        return res;
    }
};
