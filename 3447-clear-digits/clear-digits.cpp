class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i =0; i< s.length(); i++){
            if(s[i]>47 && s[i]<58){
            if(!st.empty())
            st.pop();
            else continue;
            }
            else st.push(s[i]);
        }
        string str="";
        while(st.size()!=0){
        str+=st.top();
        st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};