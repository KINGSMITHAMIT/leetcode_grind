// class Solution {
// public:
//     string removeOccurrences(string s, string p) {
//         stack<int>st;
//         stack<int>std;
//         int i=0;
//         while(s[i]!='\0'){
//         int l=p.length();
//             st.push(s[i]);
//             int k=l-1;
//             if(st.size()>=l){
//                 while(!st.empty()&&st.top()==p[k]){
//                     std.push(st.top());
//                     st.pop();
//                     k--;
//                 }
//                 if(k>=0){
//                     while(!std.empty()){
//                         st.push(std.top());
//                         std.pop();
//                     }
//                 }
//             }     
//             i++;   
//         }
//          string str="";
//             while(!st.empty()){
//                 str+=st.top();
//                 st.pop();
//             }
//             reverse(str.begin(),str.end());
//             return str;
//     }
// };


class Solution {
public:
    string removeOccurrences(string s, string p) {
        stack<char> st;
        stack<char> tempSt;
        int i = 0;
        int l = p.length();
        while (s[i] != '\0') {
            st.push(s[i]);
            int k = l - 1;
            if (st.size() >= l) {
                // Attempt to match the pattern from the stack
                while (k >= 0 && st.top() == p[k]) {
                    tempSt.push(st.top());
                    st.pop();
                    k--;
                    if (st.empty() && k >= 0) break; // Prevent stack underflow
                }
                if (k >= 0) {
                    // Pattern didn't match fully, restore characters
                    while (!tempSt.empty()) {
                        st.push(tempSt.top());
                        tempSt.pop();
                    }
                } else {
                    // Pattern matched completely, discard tempSt contents
                    while (!tempSt.empty()) {
                        tempSt.pop();
                    }
                }
            }
            i++; // Increment i to avoid infinite loop
        }
        // Reconstruct the result string
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         string result;
//         int l = part.length();
//         for (char c : s) {
//             result.push_back(c);
//             // If the end of result matches part, remove it
//             if (result.size() >= l && result.substr(result.size() - l, l) == part) {
//                 result.resize(result.size() - l);
//             }
//         }
//         return result;
//     }
// };
