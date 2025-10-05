class Solution {
public:
    vector<vector<string>>ans;
    bool check(int r , int c,int n,vector<string>&board){
        //check if there is any Q +nt in the row 
        for(int i =0 ; i<r; i++) if(board[i][c]=='Q') return false;
        //chk if there is any Q +nt it the left diagonal and the right diagonal
        // Left diagonal
for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
    if(board[i][j] == 'Q') return false;
}

// Right diagonal
for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) {
    if(board[i][j] == 'Q') return false;
}
        return 1;
    }
    void help( int r, int n, vector<string>&board ){
         if(r>=n){
            ans.push_back(board);
            return;
         }
         for(int i =0; i<n; i++){
            if(check(r,i,n, board)==false) continue;
            board[r][i]='Q';
            help(r+1,n, board);
            board[r][i]='.'; 
         }
         
    }
    vector<vector<string>> solveNQueens(int n) {
        // let's create a puzzle
        string temp(n,'.');
        vector<string>board(n,temp);
        help(0,n,board);
        return ans;
    }
};