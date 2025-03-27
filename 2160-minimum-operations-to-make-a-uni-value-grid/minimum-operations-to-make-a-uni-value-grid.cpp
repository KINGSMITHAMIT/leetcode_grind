class Solution {
public:
    int minOperations(vector<vector<int>>& vec, int x) {
        vector<int>v;
        for(int i =0;i<vec.size(); i++){
            for(int j =0; j<vec[0].size(); j++){
                v.push_back(vec[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int n = v.size();
        int median = n/2;
        int count=0;
        for(int i=0; i<n; i++){
            if(abs(v[i]-v[median])%x!=0) return -1;
            else {

                count+= abs(v[i]-v[median])/x;
                }
        }
        return count;
    }
};