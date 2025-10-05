class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        appendOne("(", 1, 0, n, ans);
        return ans;
    }

    void appendOne(string s, int open, int close, int n,  vector<string>& ans) {
        if(open < n) {
            appendOne(s+"(", open+1, close, n, ans);
        }
        if((open > close) && (close < n)) {
            appendOne(s+")", open, close+1, n, ans);
        }
        if(open == n && close == n) {
            ans.push_back(s);
        }
    }
};
