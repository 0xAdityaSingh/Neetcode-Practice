class Solution {
public:
    int helper(int n,int m, vector<vector<int>>&dp,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        return dp[i][j] = helper(n,m,dp,i-1,j)+helper(n,m,dp,i,j-1);
        
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp (n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        return helper(n,m,dp,n-1,m-1);
    }
};
