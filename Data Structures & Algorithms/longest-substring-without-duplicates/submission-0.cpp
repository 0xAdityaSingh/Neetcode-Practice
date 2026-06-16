class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int> mp;
        int l(0), e(0);

        while(l<s.size() && e<s.size()){
            if(mp.find(s[e])!=mp.end()){
                l = max(l, mp[s[e]]+1);
            }
            mp[s[e]]=e;
            e++;
            ans = max(ans, e-l);

        }

        return ans;
    }
};
