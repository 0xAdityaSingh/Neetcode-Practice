class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2;i++){
            int s = i+1;
            int e = nums.size()-1;

            while(s<e){
                if(nums[s]+nums[e]+nums[i]==0){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    while(s+1<e && nums[s]==nums[s+1]) s++;
                    while(s<e-1 && nums[e]==nums[e-1]) e--;
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]+nums[i]>0){
                    e--;
                }
                else{
                    s++;
                }
            }
            while(i+1<nums.size()-2 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};
