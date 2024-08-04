class Solution {
public:
    bool chk(vector<int>& weights, int days, int mid ){
        int n = weights.size();
        int m = mid;
        int count =1;
        for(int i =0; i< n; i++){
            if(m >= weights[i]){
                m -= weights[i];
        }
            else{
                count++;
                m =mid;
                m -=weights[i]; 
            }
        }
        if(count <= days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        auto maxit = max_element(weights.begin(), weights.end());
        int lo = *maxit;
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while(lo<=hi){
            int mid = lo + (hi - lo )/2;
            if(chk( weights, days, mid)){
                ans = mid;
                hi =mid-1;
            }
            else lo = mid+1;
        }
    return ans;
    }
};