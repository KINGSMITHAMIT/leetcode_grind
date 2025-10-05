class Solution {
public:
    vector<string>ans;
    void help(string st, int open ,int close, int n ){
        // if all my open brac == close brac then i can push this into my ans
        if(open==n&&close==n&& open==close ){ans.push_back(st);return;}
        if(open<n) help(st+'(', open+1, close, n);
        if(open>close) help(st+')', open, close+1,n);
    }
    vector<string> generateParenthesis(int n) {
        help("(",1,0,n);
        return ans;
    }
};