class Solution {
public:
vector<vector<int>>ans;
vector<int>curr;
void backtrack (int i, vector<int>freq, int target){
    if(target == 0){
        ans.push_back(curr);
        return;
    }
    if(i>=freq.size() || target<0)return;
    
    // let's skip the current element 
    backtrack(i+1, freq, target);

    // let's process the current element 

    if(freq[i]>0){
        curr.push_back(i);
        freq[i]--;
        backtrack(i, freq, target-i);
        curr.pop_back();
        freq[i]++;
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=  candidates.size();
        vector<int>freq(51,0);
        for(auto &it: candidates) freq[it]++;
        backtrack(1, freq, target);
        return ans;
    }
};