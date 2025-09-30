class Solution {
public:
    bool check(vector<vector<char>>&board, int r, int c, char ch){
        // let's check wether the no is +nt in the row 
        for(int i =0; i<9;i++){
            if(board[r][i] == ch) return 0;
            if(board[i][c] == ch) return 0;
        }
        //let's try to check in the grid the ch is +nt
        int r1 = r-r%3; int c1 = c-c%3;
        for(int i = r1; i<r1+3; i++){
            for(int j = c1; j<c1+3; j++){
                if(board[i][j]==ch) return 0;
            }
            }
            return true;
    }
    bool help(vector<vector<char>>&board, int r, int c){
        if(r==9) return 1;
        else if(c == 9) return help(board, r+1, 0);
        else if(board[r][c]!='.') return help(board, r, c+1);
        else{
            for(char ch = '1'; ch<= '9'; ch++){
                if(check(board, r, c, ch)){
                    board[r][c]=ch;
                    bool ans = help(board, r, c+1);
                    if(ans){
                        return true;
                    }
                    board[r][c]='.';
                }
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
         bool ans  = help(board, 0, 0);
    }
};