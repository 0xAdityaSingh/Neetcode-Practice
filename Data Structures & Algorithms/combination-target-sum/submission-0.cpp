class Solution {
public:
    void recursiveCombinationSum(int idx, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result){
        if(idx == candidates.size()){
            if(target == 0){
                result.push_back(temp);
            }
            return;
        }
        if(target>= candidates[idx]){
            temp.push_back(candidates[idx]);
            recursiveCombinationSum(idx, target-candidates[idx], candidates, temp,result);
            temp.pop_back();
        }
        recursiveCombinationSum(idx+1, target, candidates, temp,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        recursiveCombinationSum(0, target, candidates, temp, result);
        return result;
    }
};