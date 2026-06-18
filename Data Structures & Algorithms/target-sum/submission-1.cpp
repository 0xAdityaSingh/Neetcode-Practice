class Solution {
public:
    unordered_map<string, int> memo;

    int dfs(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size())
            return sum == target;

        string key = to_string(i) + "," + to_string(sum);
        if (memo.count(key))
            return memo[key];

        return memo[key] =
            dfs(nums, i + 1, sum + nums[i], target) +
            dfs(nums, i + 1, sum - nums[i], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, 0, target);
    }
};