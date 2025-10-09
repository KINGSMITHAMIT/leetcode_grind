class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        vector<int>ans;
        sort(potions.begin(),potions.end());
        int max_potion=potions[n-1];
        // let's try interating over the spells array and find the lowerbound of the minpotin for each spell
        for(int i = 0; i< m; i++){
            long long min_potion= ceil((1.0*success)/spells[i]);
            if(min_potion>max_potion){
                ans.push_back(0);
                continue;
            }
            int pos=lower_bound(potions.begin(), potions.end(),min_potion)-potions.begin();
            ans.push_back(n-pos);
        }
        return ans;
    }
};