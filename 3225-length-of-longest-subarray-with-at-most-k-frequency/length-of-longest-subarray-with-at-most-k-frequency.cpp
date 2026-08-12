class Solution {
public:
    // WE NEED TO iterate over the array 
    // we can create a measure of the max count of nums that can be accumulated 
    // in this case the criteria is the no. of char does not exceed a limit 
    // we will have to move the window as soon as the freq rises above k 
    // but at that time should we increase the i pointer 
    // by increasing the i counter we will decrease the freq count of a char 
    // that need not had to be the char which has the freq cout above k
    // so should we stat pointig the i pointer to the j location and then again start counting from the start will we get a usual big value 
    // this probably seems right to me 
    // let's do  this 
    int maxSubarrayLength(vector<int>& nums, int k) {
         map<long long, int>mp;
        //  for(auto &x : nums) mp[x]++;
        int i =0, j =0, n = nums.size(),  ans = 0;
        
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k) {
                mp[nums[i]]--;
                i++; 
            }
            ans = max (ans, j-i+1);
            j++;
        }
        return ans;
    }
};