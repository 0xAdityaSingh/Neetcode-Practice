class Solution {
public:
    bool inBound(char c){
        if(c>='0' && c<='9') return true;
        c = tolower(c);
        if(c>='a' && c<='z') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0;
        int e = s.size()-1;

        while(l<e){
            bool skipL = inBound(s[l]);
            bool skipE = inBound(s[e]);
            if(!skipL){
                l++;
                continue;
            }
            if(!skipE){
                e--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[e])) return false;
            l++;
            e--;
        }
        return true;
    }
};
