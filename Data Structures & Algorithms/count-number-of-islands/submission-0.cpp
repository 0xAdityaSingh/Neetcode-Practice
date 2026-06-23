class Solution {
public:
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int n,int m, int i, int j){
        vis[i][j]=true;
        for(int k = 0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 and ni<n and nj>=0 and nj < m and !vis[ni][nj] and grid[ni][nj]=='1'){
                dfs(grid, vis,n,m,ni,nj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int countIslands = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and vis[i][j]==false){
                    dfs(grid, vis, n,m, i,j);
                    countIslands++;
                }
            }
        }
        return countIslands;
    }
};