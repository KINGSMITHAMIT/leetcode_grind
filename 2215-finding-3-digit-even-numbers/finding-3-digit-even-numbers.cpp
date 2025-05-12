class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> result; // Use a set to store unique numbers
    int n = digits.size();
    
    // Iterate over all possible selections of three distinct indices
    for (int i = 0; i < n; i++) {
        if (digits[i] == 0) continue; // No leading zero
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (digits[k] % 2 != 0) continue; // Ensure the number is even
                
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                result.insert(num);
            }
        }
    }

    // Convert the set to a sorted vector
    return vector<int>(result.begin(), result.end());
}
};


vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> result; // Use a set to store unique numbers
    int n = digits.size();
    
    // Iterate over all possible selections of three distinct indices
    for (int i = 0; i < n; i++) {
        if (digits[i] == 0) continue; // No leading zero
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (digits[k] % 2 != 0) continue; // Ensure the number is even
                
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                result.insert(num);
            }
        }
    }

    // Convert the set to a sorted vector
    return vector<int>(result.begin(), result.end());
}

