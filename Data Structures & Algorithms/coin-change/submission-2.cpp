class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount+1,INT_MAX);
        dp[0]=0;
        for(int i = 0; i<=amount; i++){
            if (dp[i] == INT_MAX) continue;
            for(auto coin : coins){
                long long currIdx = (long long)i + coin;
                if(currIdx<=amount){
                    dp[currIdx] = min(dp[currIdx], dp[i]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};
