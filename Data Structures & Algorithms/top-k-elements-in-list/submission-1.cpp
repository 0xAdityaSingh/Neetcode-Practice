class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,vector<int>>freq;
       unordered_map<int,int> mp;

       for(auto num : nums){
        mp[num]++;
       }
       for(auto it : mp){
        freq[it.second].push_back(it.first);
       }
       vector<int> ans;
       int size = nums.size();
       while(ans.size()<k && size>0){
            vector<int> temp = freq[size];
            for(auto it : temp){
                ans.push_back(it);
                if(ans.size()>=k) return ans;
            }
            size--;
       }
       return ans;
    }
};
