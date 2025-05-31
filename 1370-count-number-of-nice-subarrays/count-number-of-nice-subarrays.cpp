class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    using ll=long long;
    int ps=0, ans=0;
    map<ll, ll>mp;
    mp[0]++;
    for(const auto &it : nums){
        if(it&1) ps+=1;
        else ps+=0;
        ans+= mp[ps-k];
        mp[ps]++;
        
    }
    return ans;
    }
};