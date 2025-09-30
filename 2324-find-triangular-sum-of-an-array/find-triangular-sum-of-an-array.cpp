class Solution {
public:
    int triangularSum(vector<int>& v) {
        int n = v.size();
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                v[i] = (v[i] + v[i+1]) % 10;
            }
            n--; // reduce effective size
        }
        return v[0];
    }
};