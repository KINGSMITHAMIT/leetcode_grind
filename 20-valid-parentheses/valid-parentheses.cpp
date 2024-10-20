class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 != 0) return 0;
        stack<char>st;
        for(int i = 0; i< s.length(); i++){
            if(s[i]=='(' || s[i] == '{' ||s[i] == '[' ) st.push(s[i]);
            else{
                if(st.size()== 0 || (s[i]==')'&&st.top()!='(')||(s[i]=='}'&&st.top()!='{') || (s[i]==']'&&st.top()!='[')) return 0;
                st.pop();
            }
        }
        if(st.size() == 0 ) return 1;
        else return 0;
    }
};