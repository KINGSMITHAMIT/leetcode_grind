class Solution {
public:
    vector<string>ans;
    void help(int n, string &st){
        if(n==0){
            ans.push_back(st);
            return;
        }
        if(st.empty()||st.back()=='1'){
            st.push_back('1');
            help(n-1, st);
            st.pop_back();
            st.push_back('0');
            help(n-1, st);
            st.pop_back();
        }
        else {
            st.push_back('1');
            help(n-1, st);
            st.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string st="";
        help(n,st );
        return ans;
    }
};