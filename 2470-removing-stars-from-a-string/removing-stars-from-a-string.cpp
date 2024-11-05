class Solution {
public:
    string removeStars(string s) {
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        if(!empty(st) && s[i]=='*') st.pop();
        else st.push(s[i]);
    }
    string str= "";
    while(!empty(st)){
        str += st.top();
        st.pop();
    }
    reverse(str.begin(),str.end());
    return str;
    }
};