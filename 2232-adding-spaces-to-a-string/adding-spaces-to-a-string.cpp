class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string result;
        int prev = 0;

        for (int spaceIndex : spaces) {
            result += s.substr(prev, spaceIndex - prev) + " ";
            prev = spaceIndex;
        }
        result += s.substr(prev);

        return result;
    }
};
