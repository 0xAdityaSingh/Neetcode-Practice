class Solution {
public:
    bool issafe(int row, int col, vector<string> &board, int n){
        int newrow = row;
        int newcol = col;
        while(newcol>=0 and newrow>=0){
            if(board[newrow][newcol] == 'Q') return false;
            newrow--;
            newcol--;
        }
        newrow = row;
        newcol = col;
        while(newcol>=0 and newrow<n){
            if(board[newrow][newcol] == 'Q') return false;
            newrow++;
            newcol--;
        }
        newrow = row;
        newcol = col;
        while(newcol>=0){
            if(board[newrow][newcol] == 'Q') return false;
            newcol--;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<string>> &result, vector<string>& board){
        if(col == n){
            result.push_back(board);
        }

        for(int row = 0 ; row < n ; row++){
            if(issafe(row,col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, n,result,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0,n,result,board);
        return result;
    }
};