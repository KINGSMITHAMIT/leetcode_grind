class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int>v;
        for(int i =0; i< len-1; i++){
            int x= nums[i];
            for(int j =i+1; j< len; j++){
            if(x+ nums[j]== target){
                v.push_back(i);
                v.push_back(j);
                return v;
            }
            else continue;
            
        }


        }
        return v;
    }
    
};