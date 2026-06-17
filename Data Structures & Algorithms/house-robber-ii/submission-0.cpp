class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int idx, int start) {
        if (idx < start) return 0;

        if (dp[idx] != -1) return dp[idx];

        return dp[idx] = max(
            helper(nums, dp, idx - 2, start) + nums[idx],
            helper(nums, dp, idx - 1, start)
        );
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int excludeLast =
            helper(nums, dp1, n - 2, 0);

        int excludeFirst =
            helper(nums, dp2, n - 1, 1);

        return max(excludeLast, excludeFirst);
    }
};