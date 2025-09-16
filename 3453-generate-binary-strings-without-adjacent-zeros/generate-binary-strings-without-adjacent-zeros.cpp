class Solution {
public:
    vector<vector<string>>v;
    void help(int n){
        if(n==1){
            v.push_back({"1", "0"});
            return;
        }
        help(n-1);
        vector<string>ans;
        vector<string>str=v.back();
        for(int i = 0; i<str.size(); i++){
            string st= str[i];
            //int n = st.length(); 
            if(st[n-2]=='1')   {
                 ans.push_back(st+'1');
                 ans.push_back(st+'0');
            }
            else ans.push_back(st+'1');
        }
        v.push_back(ans);
    }
    vector<string> validStrings(int n) {
        help(n);
        return v[n-1];   
    }
};

// class Solution {
// public:
//     vector<vector<string>> v;

//     void help(int n) {
//         if (n == 1) {
//             v.push_back({"0", "1"});
//             return;
//         }

//         help(n - 1); // Build smaller strings first

//         vector<string> prev = v.back();
//         vector<string> curr;

//         for (const string& st : prev) {
//             if (st.back() == '1') {
//                 curr.push_back(st + "1");
//                 curr.push_back(st + "0");
//             } else {
//                 curr.push_back(st + "1");
//             }
//         }

//         v.push_back(curr);
//     }

//     vector<string> validStrings(int n) {
//         v.clear(); // Ensure no leftover data
//         help(n);
//         return v[n - 1];
//     }
// };