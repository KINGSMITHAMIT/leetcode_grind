class Solution {
public:
    long long pickGifts(vector<int>& arr, int k) {
        for(int i = 0; i < k; i++) {
            int m = INT_MIN;
            int midx = 0;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[j] > m) {
                    m = arr[j];
                    midx = j;
                }
            }
            arr[midx] = sqrt(m);
        }
        
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }
};
