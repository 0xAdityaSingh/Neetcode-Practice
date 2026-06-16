class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int numberOfZeros = 0;
        for(auto it : nums){
            if(it == 0) numberOfZeros++;
            else{
                totalProduct*=it;
            }
        }
        vector<int> ans (nums.size(),1);

        for(int i = 0; i<nums.size();i++){
            if(numberOfZeros>1){
                ans[i]=0;
            }
            else{
                if(nums[i]==0){
                    ans[i]=totalProduct;
                }
                else if(numberOfZeros == 1){
                    ans[i]=0;
                }
                else{
                    ans[i] = totalProduct/nums[i];
                }
            }
        }
        return ans;
    }
};
