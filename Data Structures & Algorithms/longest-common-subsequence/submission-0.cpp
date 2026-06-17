class Solution {
public:
    int helper(string text1, string text2, int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        if(text1[i] == text2[j]){
            dp[i][j] = helper(text1,text2, i+1, j+1, n,m,dp)+1;
        }
        else{
            dp[i][j] = max(helper(text1,text2, i, j+1, n,m,dp),helper(text1,text2, i+1, j, n,m,dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+2, vector<int>(m+2,0));

        return helper(text1,text2, 0,0,n,m,dp);
    }
};
