class Solution {
public:
    set<vector<int>>st;
    void helper(vector<int>&v,int i , int n, vector<int>&curr ){
        if(i>=n){
            st.insert(curr);
            return;
        }
        curr.push_back(v[i]);
        helper(v, i+1, n, curr);
        curr.pop_back();
        helper(v, i+1, n , curr);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int>curr;
        helper(v, 0, n , curr);
        vector<vector<int>>ans;
        for(auto &it : st) ans.push_back(it);
        return ans;
    }
};