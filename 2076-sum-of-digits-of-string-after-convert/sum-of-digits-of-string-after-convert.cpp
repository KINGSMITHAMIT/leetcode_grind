class Solution {
public:
    int getLucky(string s, int k) {
        string l;
        for (int i =0; i< s.size(); i++){
             l += to_string(static_cast<int>(s[i])-96); 
        }
        int sum;
        while(k--){
            sum =0;
        for(int i =0; i< l.size(); i++){
         sum += l[i] - '0';  
        }
        l =  to_string(sum);
        }
        return sum;
        
    }
};


// // Solution.cpp
// #include "Solution.h"

// int Solution::getLucky(std::string s, int k) {
//     std::string l;
//     for (int i = 0; i < s.size(); i++) {
//         l += std::to_string(static_cast<int>(s[i]) - 96);
//     }

//     int sum;
//     while (k--) {
//         sum = 0;
//         for (int i = 0; i < l.size(); i++) {
//             sum += l[i] - '0';  // Convert char to int
//         }
//         l = std::to_string(sum);
//     }
//     return sum;
// }