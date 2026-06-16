class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int minNum = INT_MAX;
        int maxNum = 0;
        unordered_set<int> existNums;
        for(auto num : nums){
            minNum = min(num,minNum);
            maxNum = max(num,maxNum);
            existNums.insert(num);
        }
        int ans = 0;
        int currCount = 0;
        for(int i = minNum; i<=maxNum;i++){
            if(existNums.find(i)!= existNums.end()){
                currCount++;
                ans = max(ans, currCount);
            }
            else{
                currCount = 0;
            }
        }
        return ans;
    }
};
