class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int i = n-1, j = 0;
        //start form bottom most row till topmost row for descending order
        while(i>=0){
            int r = i, c = j;
            vector<int> arr;
            while(r<n && c<n){
                arr.push_back(grid[r][c]);
                r++, c++;
            }
            sort(arr.begin(), arr.end(), greater<int>());
            r = i, c = j;
            int ind = 0;
            while(r<n && c<n){
                grid[r][c] = arr[ind++];
                r++, c++;
            }
            i--;
        }
        //start from 2nd col to last col for ascending order
        i = 0, j = 1;
        while(j < n){
            int r = i, c = j;
            vector<int> arr;
            while(r<n && c<n){
                arr.push_back(grid[r][c]);
                r++, c++;
            }
            sort(arr.begin(), arr.end());
            r = i, c = j;
            int ind = 0;
            while(r<n && c<n){
                grid[r][c] = arr[ind++];
                r++, c++;
            }
            j++;
        }
        return grid;
    }
};