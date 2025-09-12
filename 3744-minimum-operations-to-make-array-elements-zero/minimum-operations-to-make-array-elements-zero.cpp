class Solution {
public:
    long long query(int l , int r){
        long long L = 1; 
        long long S = 1;
        long long steps=0;// to store the steps of each set of the query
        while(L<=r){
        long long R = 4*L-1; 
        long long start = max((long long)l,L);
        long long end = min((long long)r,R);
        if(start<=end){  //this step seems pointless to me like why do i even check wether or not my start is less than end if it is min(r, R) if my while loop is always ensur ing that L<r
            long long totalNoOfPeople = (end - start+1);
            long long totalSteps = totalNoOfPeople*S;
            steps+= totalSteps;
        }
        S++;
        L=R+1;
        }
        return steps;
    }

    long long minOperations(vector<vector<int>>& q) {
        long long ans=0;
        int n = q.size();
        for(int i =0 ; i<n ; i++){
           long long count = query(q[i][0], q[i][1]);
           ans+= (count+1)/2;
        }
        return ans;
    }
};