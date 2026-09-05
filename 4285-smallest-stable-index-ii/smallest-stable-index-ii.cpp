class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // let's get the instablility score 
        // like i need to get the min index of instablity score less than k 
        // let find out the max and the min ele 
        // in o(n)
        // let's create a minimum value from index i t0 n-1
        // like we will iterate from the back to the front to get the minimum index from i to n-1
        int minE = INT_MAX, maxE = INT_MIN, n =nums.size();
        vector<int>minEle(n);
        for(int i =n-1; i>=0; i--){
            minE = min(minE, nums[i]); 
            minEle[i]=minE;          
        }
        // let's iterate over to get the max index ele from 0 to n-1
        for(int i = 0; i<n; i++){
            maxE =max(maxE, nums[i] );
            if(maxE-minEle[i]<= k) return i; 
        }
        return -1;
    }
};