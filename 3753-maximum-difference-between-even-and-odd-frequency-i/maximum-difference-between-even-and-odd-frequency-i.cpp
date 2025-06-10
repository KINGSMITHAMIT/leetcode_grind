class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(const auto &it: s){
            mp[it]++;
        }
        int mo=0, me=INT_MAX;
        for(auto &it :mp){
            if(it.second&1)    mo= max(mo,it.second);
            else if(it.second%2==0) me= min(me, it.second);
        }
        if(me==INT_MAX) return mo;
        else    return mo-me;
    }
};

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxDifference(string s) {
//         map<char, int> mp;
//         for (const auto &it : s) {
//             mp[it]++;
//         }

//         int mo = 0, me = INT_MAX; // Fix `me` initialization
//         for (auto &it : mp) {
//             if (it.second & 1) // Check if frequency is odd
//                 mo = max(mo, it.second);
//             else
//                 me = min(me, it.second);
//         }

//         return (me == INT_MAX) ? mo : mo - me; // Handle cases with no even frequency
//     }
// };