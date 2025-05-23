// class Solution {
// public:
//     string frequencySort(string s) {
//         map<char, int>mp;
//         for(const auto &it : s){
//             mp[it]++;
//         }
//         vector<pair<char, int>>v(mp.begin(), mp.end());
//          sort(v.begin(), v.end(), [](const pair<char , int> &a, const pair<char, int> &b) {
//         return a.second>b.second;
//     });
//     string st="";
//     for(const auto &it: v){
//         while(it.second--) st+= it.first;
//     }
//     return st;
//     }
// };

// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp; 
        for (const char &it : s) {
            mp[it]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second; 
        });

        string st = "";
        for (const auto &[ch, freq] : v) {
            st += string(freq, ch); 
        }

        return st;
    }
};