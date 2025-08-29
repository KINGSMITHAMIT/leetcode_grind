class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        // Hours: 0–11, use 4 bits; Minutes: 0–59, use 6 bits
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                // Count bits in hour and minute
                int bits = __builtin_popcount(h) + __builtin_popcount(m);
                if (bits == turnedOn) {
                    // Format time as "H:MM"
                    ostringstream oss;
                    oss << h << ':' << setw(2) << setfill('0') << m;
                    res.push_back(oss.str());
                }
            }
        }
        return res;
    }
};