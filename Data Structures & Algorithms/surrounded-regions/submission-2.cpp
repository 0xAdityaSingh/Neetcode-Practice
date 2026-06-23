class Solution {
public:
    vector<int> dx{1,-1,0,0};
    vector<int> dy{0,0,1,-1};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j,int n,int m){
        vis[i][j]=true;
        for(int k = 0; k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==false && board[ni][nj]=='O'){
                dfs(board,vis,ni,nj,n,m);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((i==0 || i==n-1 || j== 0 || j==m-1) && board[i][j]=='O' && vis[i][j]==false){
                    dfs(board, vis,i,j,n,m);
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]=='O' && vis[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
