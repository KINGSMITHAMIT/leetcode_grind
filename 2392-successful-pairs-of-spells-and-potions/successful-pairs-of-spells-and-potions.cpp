class Solution {
public:
    vector<int>ans;
    void bs(vector<int>&potions, int spell, long long success ){
        int n = potions.size();
        long long minpotion =ceil((1.0*success)/spell);
        if(minpotion>potions[n-1]){
            ans.push_back(0);
            return;
        }
        int low = 0;
        int hi = n-1;
        while(low < hi){
            int mid = low+(hi-low)/2;
            if(potions[mid]<minpotion) low=mid+1;
            else hi=mid;
        }
        ans.push_back(n-low);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        sort(potions.begin(),potions.end());
        for(int i = 0; i<m; i++){
            bs(potions, spells[i], success);
        }
        return ans;
    }
};