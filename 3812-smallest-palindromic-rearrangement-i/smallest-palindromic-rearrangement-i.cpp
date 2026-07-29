class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int len = n/2;
        string str = s.substr(0, len);
        sort(str.begin(), str.end());
        string rev_str =str; 
        reverse(rev_str.begin(),rev_str.end());
        if(n&1) return str+s[len]+rev_str;
        else return str+rev_str;
    }
};