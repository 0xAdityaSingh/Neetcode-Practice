class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int idx,int start){
        if(idx<start) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(helper(nums,dp,idx-1,start), helper(nums,dp,idx-2,start)+nums[idx]);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp1 = vector<int>(101,-1);
        vector<int> dp2 = vector<int>(101,-1);
        return max(helper(nums,dp1,nums.size()-1,1),helper(nums,dp2,nums.size()-2,0));
    }
};
