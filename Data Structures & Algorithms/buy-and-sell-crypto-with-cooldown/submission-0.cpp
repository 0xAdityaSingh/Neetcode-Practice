class Solution {
public:
    int helper(vector<int>& prices, unordered_map<string,int> &dp, int i,bool canBuy){
        if(i>=prices.size()) return 0;
        string key = to_string(i)+"-"+to_string(canBuy);
        if(dp.find(key)!=dp.end()) return dp[key];

        int cooldown = helper(prices, dp, i+1, canBuy);
        if(canBuy){
            dp[key] = max(helper(prices, dp, i+1, false)-prices[i], cooldown);
        }
        else{
            dp[key] = max(helper(prices, dp, i+2, true)+prices[i], cooldown);
        }
        return dp[key];
    }
    int maxProfit(vector<int>& prices) {
        unordered_map<string,int> dp;
        return helper(prices, dp, 0, true);

    }
};
