class Solution {
public:
    vector<string>ans;
    void help(int i, string& d, map<char, vector<char>>&mp){
        if(i == d.length()){
            ans.push_back(d);
            return;
        }
        for(auto it: mp[d[i]]){
            char ch = d[i];
            d[i]=it;
            help(i+1, d, mp);
            d[i]= ch;
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        map <char, vector<char>> mp;
        mp['2']= {'a','b','c'}; mp['3']={'d','e','f'};mp['4']= {'g','h','i'}; mp['5']={'j','k', 'l'};
        mp['6']={'m', 'n', 'o'}; mp['7']={'p', 'q','r', 's'}; mp['8']={'t','u', 'v'}; mp['9']={'w','x','y','z'}; 
        help(0, digits, mp);
        return ans;
    }
};