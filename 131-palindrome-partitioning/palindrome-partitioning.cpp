// class Solution {
// public:
//     vector<vector<string>>ans;
//     vector<string>palindrome;
//     bool isPalindrome(string st, int left, int right ){
//         for(int  i  = left ; i<=right; i++){
//             if(st[i]!=st[right-(i-left)]) 
//                 return 0;   
//         }
//             return 1;
//     }
//     void bactrack(string &st, int index, vector<string>&palindrome ){
//         if(index == st.size()){
//             ans.push_back(palindrome);
//             return;
//         }
//         string temp="";
//         for(int i = index; i<st.size(); i ++){
//             temp+=st[i];
//             if(isPalindrome(st, index, i  )){
//                 palindrome.push_back(temp);
//                 backtrack(st,i+1,palindrome);
//                 palindrome.pop_back();
//             }

//         }

//     }
//     vector<vector<string>> partition(string s) {
//         backtrack(s, 0, palindrome);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> palindrome;

    bool isPalindrome(string st, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (st[i] != st[right - (i - left)])
                return 0;
        }
        return 1;
    }

    void backtrack(string &st, int index, vector<string> &palindrome) {
        if (index == st.size()) {
            ans.push_back(palindrome);
            return;
        }
        string temp = "";
        for (int i = index; i < st.size(); i++) {
            temp += st[i];
            if (isPalindrome(st, index, i)) {
                palindrome.push_back(temp);
                backtrack(st, i + 1, palindrome); 
                palindrome.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0, palindrome);
        return ans;
    }
};