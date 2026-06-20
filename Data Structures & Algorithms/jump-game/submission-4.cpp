class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1) return false;
        vector<bool> vis(nums.size(), false);
        vis[0] = true;
        for(int i =0;i<nums.size();i++){
            if(vis[i] == true){
                for(int j = i+1; j<=i+nums[i];j++){
                    if(j>=nums.size()){
                        break;
                    }
                    vis[j] = true;
                }
            }
        }
        return vis[nums.size()-1];
    }
};
