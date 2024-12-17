#include <string>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
public:
    string repeatLimitedString(std::string s, int repeatLimit) {
        // Initialize frequency array for characters
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Use a string builder equivalent
        string result;
        int index = 25; // Start from the largest character

        while (index >= 0) {
            if (freq[index] == 0) {
                index--;
                continue;
            }

            int used = min(freq[index], repeatLimit);
            for (int k = 0; k < used; k++) {
                result.push_back('a' + index);
            }
            freq[index] -= used;

            if (freq[index] > 0) { // Find a smaller character
                int prevIndex = index - 1;
                while (prevIndex >= 0 && freq[prevIndex] == 0) {
                    prevIndex--;
                }
                if (prevIndex < 0) {
                    break;
                }
                result.push_back('a' + prevIndex);
                freq[prevIndex]--;
            }
        }

        return result;
    }
};
