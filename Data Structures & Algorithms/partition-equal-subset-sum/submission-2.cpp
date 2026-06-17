class Solution {
public:
    bool helper(vector<int>&nums, vector<bool>&dp,int target,int idx){
        if(idx>=nums.size() || target<0) return false;
        if(target == 0) return true;
        return dp[target] = helper(nums, dp, target-nums[idx], idx+1) || helper(nums, dp, target, idx+1);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto it : nums){
            totalSum+=it;
        }
        if(totalSum%2!=0) return false;
        vector<bool> dp((totalSum/2)+1,false);
        return helper(nums,dp,totalSum/2, 0);

    }
};
