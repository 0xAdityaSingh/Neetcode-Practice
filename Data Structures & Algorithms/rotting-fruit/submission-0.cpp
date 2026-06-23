class Solution {
public:
    vector<int> vx {0,0,-1,1};
    vector<int> vy {-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i <m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int newx = it.first.first;
            int newy = it.first.second;
            int time = it.second;
            result = max(result,time);
            for(int i = 0; i<4 ; i++){
                int nvx = newx + vx[i];
                int nvy = newy + vy[i];
                if(nvx>=0 and nvx<m and nvy>=0 and nvy<n and grid[nvx][nvy]==1){
                    grid[nvx][nvy]=2;
                    q.push({{nvx,nvy},time+1});
                }
            }
        }
        for(int i = 0; i <m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return result;
    }
};