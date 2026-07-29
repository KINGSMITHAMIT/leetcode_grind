class Solution {
public:
    string smallestPalindrome(string s) {
    int n = s.size();

    int freq[26] = {0};

    // Count only the left half
    for (int i = 0; i < n / 2; i++) {
        freq[s[i] - 'a']++;
    }

    int left = 0;
    int right = n - 1;

    // Process characters from a -> z
    for (int i = 0; i < 26; i++) {

        while (freq[i] > 0) {

            char ch = 'a' + i;

            s[left] = ch;
            s[right] = ch;

            left++;
            right--;

            freq[i]--;
        }
    }

    return s;
}
};