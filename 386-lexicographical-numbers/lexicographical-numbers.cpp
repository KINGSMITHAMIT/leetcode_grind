// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<vector<int>>v(10);
//         for(int i =1; i<=n; i++){
//             string st= to_string(i);
//             int d= st[0]-'0';
//             v[d].push_back(i);
//         }
//         vector<int>ans;
//         for(int i = 1; i<=9; i++){
//             for(auto &it : v[i])
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
        }
        sort(ans.begin(), ans.end(), [](int a, int b) {
            return to_string(a) < to_string(b); // Compare as strings
        });
        return ans;
    }
};