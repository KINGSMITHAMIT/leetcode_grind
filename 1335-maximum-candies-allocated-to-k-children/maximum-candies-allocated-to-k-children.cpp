class Solution {
public:
    int maximumCandies(vector<int>& arr, long long k) {
        if(k==0) return 0;
        long long total=0;
        int lo=1, hi=0,mid,maxc;
        for(int x: arr ) {
            hi=max(hi, x);
            total+=x;
        }
        if(total<k) return 0;
        while(lo<=hi){
            mid=lo+((hi-lo)/2);
            long long c=0;
            for(int x : arr){
                c+=x/mid;
            }
            if(c>=k){
                maxc=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return maxc;
    }
};


// class Solution {
// public:
//     int maximumCandies(vector<int>& arr, long long k) {
//         long long total = accumulate(arr.begin(), arr.end(), 0LL);
//         if (total < k) return 0;  // Edge case: insufficient candies
        
//         int lo = 1;
//         int hi = *max_element(arr.begin(), arr.end());
//         int ans = 0;
        
//         while (lo <= hi) {
//             int mid = lo + (hi - lo) / 2;
//             long long c = 0;  // Prevent overflow
            
//             for (int x : arr) {
//                 c += x / mid;
//             }
            
//             if (c >= k) {
//                 ans = mid;     // Track largest valid mid
//                 lo = mid + 1;  // Try higher values
//             } else {
//                 hi = mid - 1;  // Reduce upper bound
//             }
//         }
        
//         return ans;
//     }
// };
