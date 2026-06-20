class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int currMax = 0;

        for(int i = 0; i<nums.size();i++){
            currMax += nums[i];
            if(currMax<0) currMax = 0;
            ans = max(ans, currMax);
        }
        if(ans == 0){
            ans = *max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};
