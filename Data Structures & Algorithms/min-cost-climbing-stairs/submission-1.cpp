class Solution {
public:
    int helper(vector<int>& cost, vector<int>& dp, int idx){
        if(idx == 2) return min(cost[0],cost[1]);
        if(idx<2) return 0;
        if(dp[idx]!=INT_MAX) return dp[idx];
        return dp[idx] = min(
            helper(cost, dp, idx - 1) + cost[idx - 1],
            helper(cost, dp, idx - 2) + cost[idx - 2]
        );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = vector<int>(101, INT_MAX);
        return helper(cost,dp,cost.size());
    }
};
