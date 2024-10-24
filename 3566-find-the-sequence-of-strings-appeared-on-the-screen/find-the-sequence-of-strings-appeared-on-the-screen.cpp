class Solution {
public:
    vector<string> stringSequence(string target) {
        string s;
     vector<string> st;
     int n = target.length();
     for(char ch : target){
        for(int j = 97; j<= (int)ch; j++){
            s += (char)j;
            st.push_back(s);
            s.pop_back();
            if(j == (int)ch) s += (char)j; 
        }
     }
     return st;
    }
};