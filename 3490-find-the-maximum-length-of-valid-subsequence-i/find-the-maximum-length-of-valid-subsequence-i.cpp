// class Solution {
// public:
//     int maximumLength(vector<int>& n) {
//         int ce = 1, co = 1, c = 1;
//         for (int i = 1; i < n.size(); i++) {
//         if (((n[i] & 1) == 1) && ((n[i] & 1) == (n[i - 1] & 1))) co++;
//         else if(((n[i] & 1) == 0) && ((n[i] & 1) == (n[i - 1] & 1))) ce++;
//         else  c++;
//         c = max(c, max(co, ce));
//         }
//         return c;
//     }
// };

class Solution {
public:
    int maximumLength(vector<int>& n) {
        int ce = 0, co = 0, c = 1;
        for (int i = 0; i < n.size(); i++) {
            if(n[i]&1) co++;
            else ce++;
            if(i!=0 && ((n[i]&1)!=(n[i-1]&1))) c++;
        }
        return max(c, max(co, ce));
    }
};

// class Solution {
// public:
//     int maximumLength(vector<int>& n) {
//         int ce = 1, co = 1, c = 1;
//         for (int i = 1; i < n.size(); i++) {
//             if ((n[i] & 1) == (n[i - 1] & 1)) {
//                 ce++;
//                 co = 1;
//             } else {
//                 co++;
//                 ce = 1;
//             }
//             c = max(c, max(co, ce));
//         }
//         return c;
//     }
// };
// if (n[i]&1 == !(n[i-1]&1))