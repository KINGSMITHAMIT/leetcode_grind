class Solution {
public:
        vector<int>dx={0, 0, 1,-1};
        vector<int>dy={-1, 1, 0, 0};
    bool helper(int i, int j, int m, int n, vector<vector<char>>&board, string word ){
        if(word.size()==0)return true;
        //inputdata -->> substask-->> basecase
         if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[0]) return false;
         // yes the char is present 
         char ch = board[i][j];
         board[i][j]='*';
         bool ans = false; // why??
         string str= word.substr(1);
         for(int k =0; k<4; k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            ans|= helper(nr, nc, m,n, board,str); 
         }
         board[i][j]=ch;
         return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j]==word[0]) {
                   bool ans= helper(i,j,m,n, board, word );
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};