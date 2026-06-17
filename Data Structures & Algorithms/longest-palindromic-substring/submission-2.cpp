class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        int start(0), end(0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            int l = i;
            int e = i;
            //odd
            while(l>=0 && e<n && s[l]==s[e]){
                if(end-start < e-l){
                    end = e;
                    start = l;
                }
                e++;
                l--;
            }


            l = i;
            e = i+1;
            //even
            while(l>=0 && e<n && s[l]==s[e]){
                if(end-start < e-l){
                    end = e;
                    start = l;
                }
                e++;
                l--;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
