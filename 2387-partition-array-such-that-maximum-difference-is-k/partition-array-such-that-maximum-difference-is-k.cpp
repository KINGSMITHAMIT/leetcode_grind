class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
     sort(nums.begin(), nums.end());
     int minEle= nums[0], count =1;
     int n= minEle+k;
     for(int i =0; i<nums.size(); i++){
        if(nums[i]>n){
            minEle=nums[i];
            count++;
            n= minEle+k;
        }
        else continue;
     }   
     return count;
    }
};