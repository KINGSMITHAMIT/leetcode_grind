// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.length()!= t.length()) return false;
//         else{
//             int n= s.length();
//             bool flag = true;
//             unordered_map <char, int> mps;
//             unordered_map <char, int> mpt;
//             for(int i =0 ; i<n; i++){
//                 mps[s[i]]++;
//                 mpt[t[i]]++;
//             }
//             for(int i =0; i< n; i++){
//                 if(mps[s[i]]!= mpt[t[i]]) {
//                     flag = false;
//                     break;
//                 }
//             }
//         return flag;
//         }
        
        

//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mps, mpt;

        for (int i = 0; i < s.length(); i++) {
            if (mps.count(s[i]) && mps[s[i]] != t[i]) return false;
            if (mpt.count(t[i]) && mpt[t[i]] != s[i]) return false;

            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }

        return true;
    }
};