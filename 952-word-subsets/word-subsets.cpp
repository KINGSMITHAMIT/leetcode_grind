class Solution {
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& A, std::vector<std::string>& B) {
        std::vector<int> bmax(26, 0);
        for (const std::string& b : B) {
            std::vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i)
                bmax[i] = std::max(bmax[i], bCount[i]);
        }

        std::vector<std::string> ans;
        for (const std::string& a : A) {
            std::vector<int> aCount = count(a);
            bool isSubset = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                ans.push_back(a);
            }
        }

        return ans;
    }

private:
    std::vector<int> count(const std::string& S) {
        std::vector<int> ans(26, 0);
        for (char c : S)
            ans[c - 'a']++;
        return ans;
    }
};
