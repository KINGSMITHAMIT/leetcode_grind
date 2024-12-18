class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> ans;
        int n = prices.size();
        ans.push_back(prices[n-1]);
        st.push(prices[n-1]);
        for(int i = n-2; i>=0; i--){
            while(st.size()>0 && prices[i]<st.top()) st.pop();
            if(st.size()== 0) ans.push_back(prices[i]);
            else ans.push_back(prices[i]-st.top());
            st.push(prices[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};