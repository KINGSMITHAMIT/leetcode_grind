class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>v=nums;
        while(v.size()!=1){
            vector<int>ans;
            for(int i =0 ; i< v.size()-1; i++) ans.push_back((v[i]+v[i+1])%10);
            v = move(ans); // this prevents us from making a copy of ans vector and then transfering it in to my vector v the stl of c++ allows us to do in through move which directly empt
        }
        return v[0];
    }
};