class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;

        for(auto it : nums){
            count[it]++;
        }
        for(auto it : count){
            if(it.second == 1) return it.first;
        }
    }
};
