class Solution {
public:
    int findMaxLength(vector<int>& v) {
        map<int, int> mp;
        int ans= 0, sum=0;
        for(int i =0; i< v.size(); i++){
            if(v[i]== 0) sum+=-1;
            else sum+=1;
            if(sum ==0) ans= (i+1); // for the length of the possible no. of elemets of same no's of 1's and 0's
            else{
                if(mp.count(sum)) ans= max(ans, i- mp[sum]);
                else mp[sum] =i;
            }
        }
        return ans;
    }
        
};