class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp,int idx){
        if (idx < 0) return 0;
        if (idx == 0) return nums[0];
        if (idx == 1) return max(nums[0], nums[1]);
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(helper(nums,dp,idx-2)+nums[idx], helper(nums,dp,idx-1));
    }
    int rob(vector<int>& nums) {
        vector<int> dp = vector<int>(101,-1);
        return helper(nums,dp,nums.size()-1);
    }
};
