class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f1 = false;
        bool f2 = false;
        bool f3 = false;

        for(auto it : triplets){
            if(it[0] == target[0] && it[1] <= target[1] && it[2] <= target[2]) f1 = true;
            if(it[1] == target[1] && it[0] <= target[0] && it[2] <= target[2]) f2 = true;
            if(it[2] == target[2] && it[1] <= target[1] && it[0] <= target[0]) f3 = true;
        }
        if(f1 && f2 && f3) return true;
        return false;
    }
};
