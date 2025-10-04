class Solution {
public:
    vector<int> dx={0,0,-1,1};
    vector<int> dy={-1,1,0,0};
    int helper(int r,int c, int cnt, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        int m = grid.size(), n = grid[0].size();
        if(r<0||r>=m|c<0||c>=n||vis[r][c]==1||grid[r][c]==-1){
            return 0;
        }
        else if(grid[r][c]==2){
            return (cnt==-1);// because we are also decrementing it for the current starting cell
        }
        vis[r][c]=1;
        int ans =0;// why am i trying to even define the ans as 0 every time
        for(int i = 0; i<4 ; i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            ans+=helper(nr, nc, cnt-1, grid, vis);
        }
        vis[r][c]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        // one thing that you need to make sure is that u iterate every cell once and do not go again to the same cell 
        // let's find the starting r and c
        int m= grid.size();
        int n = grid[0].size();
        int count =0, r, c; // lets count the no of empty cells, my starting r and c
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1) {
                    r=i;
                    c=j;
                }
                else if(grid[i][j]==0) count++;
            }
        }
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        int ans = helper(r,c, count, grid, vis);
        return ans;
    }
};