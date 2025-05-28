class Solution {
public:
    int findMaxLength(vector<int>& v) {
        unordered_map<int, int> ump;
        int ans= 0, sum=0;
        for(int i =0; i< v.size(); i++){
            if(v[i]== 0) sum+=-1;
            else sum+=1;
            if(sum ==0) ans= (i+1); // for the length of the possible no. of elemets of same no's of 1's and 0's
            else{
                if(ump.count(sum)) ans= max(ans, i- ump[sum]);
                else ump[sum] =i;
            }
        }
        return ans;
    }
        
};