class Solution {
public:
//the solution to the code has been written to find the lower right side point
    bool customSort(vector<int>a, vector<int>b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0]; 
    }
    int numberOfPairs(vector<vector<int>>& v) {
        int n = v.size();
        int count=0;
        // sort(vector<vector<int>>points.begin(), vector<vector<int>>point.end(), customSort);
        for(int i =0; i<n ; i++){
            //the upper point
            int x1= v[i][0];
            int y1= v[i][1];
            for(int j =0; j<n; j++ ){
                if(i == j )continue;
                //the lower point
                int x2 = v[j][0];
                int y2 = v[j][1];
                // this point is lower obviously but still do we not have to check wether there exist a point in between them
                if(x1<=x2&&y1>=y2){
                    bool isPointInside= false;
                    for(int k = 0; k<n; k++){
                    if(k == i || j == k) continue;
                    int x3 = v[k][0];
                    int y3 = v[k][1];
                    if((x3>=x1&&x3<=x2)&&(y3>=y2&&y3<=y1)){
                        isPointInside= true;
                        break;
                    }
                    }
                    if(!isPointInside) count++;
                }
            }
        }
        return count;
    }
};