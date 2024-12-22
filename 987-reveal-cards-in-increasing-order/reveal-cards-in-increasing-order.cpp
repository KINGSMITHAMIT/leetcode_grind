class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        sort(d.begin(), d.end());
        queue<int>q;
        for(int i =0; i<d.size();i++){
            q.push(i);
        }
        vector<int>ans(d.size());
        for(int i = 0; i<d.size();i++){
            ans[q.front()]= d[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};