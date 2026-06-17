class Solution {
public:
    int dfs(string& s, vector<int>& dp, int idx) {
        if (idx == s.size()) return 1;

        if (s[idx] == '0') return 0;

        if (dp[idx] != -1) return dp[idx];

        int res = dfs(s, dp, idx + 1);

        if (idx + 1 < s.size() &&
            (s[idx] == '1' ||
             (s[idx] == '2' && s[idx + 1] <= '6'))) {
            res += dfs(s, dp, idx + 2);
        }

        return dp[idx] = res;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return dfs(s, dp, 0);
    }
};