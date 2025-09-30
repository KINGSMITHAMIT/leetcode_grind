class Solution {
public:
    vector<vector<string>>ans;
    bool check(vector<string>&board, int r, int c, int n){
        for(int i = 0; i<=r ; i++)  if(board[i][c] == 'Q') return 0;
        for(int  i = r-1, j = c-1; i>=0&& j>=0; i--, j--) if(board[i][j]=='Q') return 0;
        for(int i = r-1, j =c+1;i>=0&& j<n; i--, j++  ) if(board[i][j]=='Q') return 0;
        return 1;
    }
    void help(vector<string>&board, int r, int n){
        if(r==n) { 
            ans.push_back(board);   
            return;
            }
        for(int i = 0 ; i< n; i++){
            if(check(board, r, i,  n )){
                board[r][i]='Q';
                help(board, r+1, n);
                board[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp(n,'.');
        vector<string>board(n,temp);
        help(board, 0, n);
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<string>> ans;

//     bool check(vector<string>& board, int r, int c, int n) {
//         // check column
//         for (int i = 0; i < r; i++)
//             if (board[i][c] == 'Q') return false;

//         // check upper-left diagonal
//         for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
//             if (board[i][j] == 'Q') return false;

//         // check upper-right diagonal
//         for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++)
//             if (board[i][j] == 'Q') return false;

//         return true;
//     }

//     void helper(vector<string>& board, int r, int n) {
//         if (r == n) {
//             ans.push_back(board); // push the whole board (vector<string>)
//             return;
//         }
//         for (int i = 0; i < n; i++) {
//             if (check(board, r, i, n)) {
//                 board[r][i] = 'Q';
//                 helper(board, r + 1, n);
//                 board[r][i] = '.'; // backtrack
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.')); // n rows, each row is "...."
//         helper(board, 0, n);
//         return ans;
//     }
// };