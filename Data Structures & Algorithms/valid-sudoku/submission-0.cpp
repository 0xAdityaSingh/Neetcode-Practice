class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(board[i][j]!='.'){
                    int tempi = i+1;
                    int tempj = j+1;
                    while(tempi<n){
                        if(board[i][j]==board[tempi][j]) return false;
                        tempi++;
                    }
                    while(tempj<m){
                        if(board[i][j]==board[i][tempj]) return false;
                        tempj++;
                    }
                    tempi = (i/3)*3;
                    tempj = (j/3)*3;
                    for(int k = tempi; k<tempi+3; k++){
                        for(int l = tempj; l<tempj+3; l++){
                            if(k == i && l == j) continue;
                            if(board[i][j] == board[k][l]) return false;
                        }   
                    }
                }
            }
        }
        return true;
    }
};
