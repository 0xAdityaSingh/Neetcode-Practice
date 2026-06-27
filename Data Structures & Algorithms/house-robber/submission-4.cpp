class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int idx){
        if(idx<0) return 0;
        else if(idx == 0) return nums[0];
        else if(idx<2) return max(nums[0],nums[1]);
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(helper(nums,dp,idx-1),helper(nums,dp,idx-2)+nums[idx]);
    }
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+1,-1);
        return helper(nums,dp,nums.size()-1);
    }
};
