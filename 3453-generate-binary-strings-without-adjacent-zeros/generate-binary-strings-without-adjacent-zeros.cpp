class Solution {
public:
    vector<string>ans;
    void help(int n, string st){
        if(n==0){
            ans.push_back(st);
            return;
        }
        if(st.empty()||st.back()=='1'){
            help(n-1, st+'1');
            help(n-1, st+'0');
        }
        else {
            help(n-1, st+'1');
        }
    }
    vector<string> validStrings(int n) {
        help(n,"" );
        return ans;
    }
};