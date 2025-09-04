class Solution {
public:
//the solution to the code has been written to find the lower right side point
    static bool customSort(vector<int>a, vector<int>b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0]; 
    }
    int numberOfPairs(vector<vector<int>>& v) {
        int n = v.size();
        int count=0;
        sort(v.begin(),v.end(), customSort);
        for(int i =0; i<n ; i++){
            //the upper point
            int x1= v[i][0];
            int y1= v[i][1];
            int maxy = INT_MIN;
            for(int j = i+1; j<n; j++ ){ 
                int x2 = v[j][0];
                int y2 = v[j][1];
                if(y2>y1) continue;
                if(y2>maxy) {
                        count++;
                        maxy = max(maxy, y2);
                 }
                
                
            }
        }
        return count;
    }
};