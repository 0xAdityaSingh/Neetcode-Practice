class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(coins.size() + 1,
                            vector<int>(amount + 1, 0));

        return dfs(0, amount, coins, memo);
    }

    int dfs(int i, int a, vector<int>& coins, vector<vector<int>>& memo) {
        if (a == 0) return 1;
        if (i >= coins.size()) return 0;
        if (memo[i][a] != 0) return memo[i][a];

        if (a >= coins[i]) {
            memo[i][a] = dfs(i + 1, a, coins, memo)+dfs(i, a - coins[i], coins, memo);
        }
        return memo[i][a];
    }
};