class Solution {
public:
    using ll=long long;
    static const int N=1e5+2; // max array can go upto 1e7;
    ll v[N];
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {
        set<ll>st;
        // vector<ll>v(20002,0);
        for(int i=0; i<s.size(); i++){
            st.insert(s[i][0]);
            st.insert(s[i][1]);
            v[s[i][0]]+=s[i][2];
            v[s[i][1]]-=s[i][2];
        }
        for(ll i=1; i<(sizeof(v)/sizeof(v[0])); i++)v[i]+=v[i-1];  // sweep line
        vector<ll>ans(st.begin(),st.end());
        vector<vector<ll>>res;
        for(int i =1; i<ans.size(); i++){
            if(v[ans[i-1]]!=0)
            res.push_back({ans[i-1],ans[i], v[ans[i-1]]});
        }
        return res;
    }
};