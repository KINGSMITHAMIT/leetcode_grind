class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans=0;
        for(int mask=0; mask<(1<<n); mask++){
            bool flag = 1;
            for(int i =0; i<n; i++){
                if(!(mask&(1<<i))) continue;
                for(int j=0; j<n; j++){
                    if (statements[i][j] == 2) continue;
                    int good= (mask&(1<<j))? 1:0;
                    if(statements[i][j]!=good){
                        flag=false;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag){
                ans = max(ans,__builtin_popcount(mask));     
            }
        }
        return ans;
    }
};

