class Solution {
public:
    vector<int> dx{0,0,1,-1};
    vector<int> dy{1,-1,0,0};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, int i,int j, int n, int m){
        vis[i][j]=true;
        int count = 1;
        for(int k =0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1 && vis[ni][nj]==false){
                count+=dfs(grid,vis,ni,nj,n,m);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int answer = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    answer = max(answer, dfs(grid,vis,i,j,n,m));
                }
            }
        }
        return answer;
    }
};
