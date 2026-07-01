class Solution {
public:
    string minWindow(string s, string t) {
        int l(0),r(0);
        int ansl(0),ansr(INT_MAX);
        int req = 0;
        unordered_map<char, int> mp;
        for(auto c : t){
            mp[c]++;
        }
        req = t.size();
        
        while(r<s.size()){
            if(mp.count(s[r])){
                if(mp[s[r]]>0){
                    req--;
                }
                mp[s[r]]--;
            }
            
            
            while(req == 0){
                if(r - l +1 < ansr - ansl){
                    ansr = r+1;
                    ansl = l;
                }
                if(mp.count(s[l])){
                    mp[s[l]]++;
                    if(mp[s[l]]>0){
                        req++;
                    }
                }
                l++;
            }
            r++;
        }

        return ansr == INT_MAX ? "" : s.substr(ansl, ansr - ansl);
    }
};