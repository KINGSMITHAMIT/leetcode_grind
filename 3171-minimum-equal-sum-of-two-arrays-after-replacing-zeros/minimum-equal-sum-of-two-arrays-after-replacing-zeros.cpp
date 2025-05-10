class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        using ll =long long;
         ll ms1=0, ms2=0, z1=0, z2=0;
         for( ll x: nums1) {
            if(x==0){
                z1++;
                ms1++;
            }
            else ms1+=x;
            }
            for( ll x: nums2) {
            if(x==0){
                z2++;
                ms2++;
            }
            else ms2+=x;
            }
            if((ms1<ms2 && z1==0) ||(ms2<ms1&& z2==0)) return -1;
            else return max<ll>(ms1,ms2);
         
    }
};  

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     long long minSum(vector<int>& nums1, vector<int>& nums2) {
//         using ll = long long;

//         ll ms1 = 0, ms2 = 0;
//         int z1 = 0, z2 = 0;

//         for (ll x : nums1) {
//             if (x == 0) z1++;
//             else ms1 += x;
//         }

//         for (ll x : nums2) {
//             if (x == 0) z2++;
//             else ms2 += x;
//         }

//         if ((ms1 < ms2 && z1 == 0) || (ms2 < ms1 && z2 == 0)) 
//             return -1;

//         return max(ms1 + z1, ms2 + z2); // Adjusted for zero replacement
//     }
// };