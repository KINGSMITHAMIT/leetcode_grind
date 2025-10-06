class Solution {
public:
    vector<string> ipAddresses;

    // Check if a substring is a valid IP segment
    bool isOkay(string s) {
        long number = stol(s);
        string actualString = to_string(number);
        return actualString == s && number <= 255;
    }

    // Backtracking function to build IP segments
    void backtrack(int index, int sections, string &s, string current) {
        if(sections == 4 && index == s.size()) {
            current.pop_back(); // remove trailing dot
            ipAddresses.push_back(current);
            return;
        }
        if(sections == 4 || index == s.size()) return;

        for(int len = 1; len <= 3; len++) {
            if(index + len <= s.size()) {
                string segment = s.substr(index, len);
                if(isOkay(segment)) {
                    backtrack(index + len, sections + 1, s, current + segment + ".");
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(0, 0, s, "");
        return ipAddresses;
    }
};