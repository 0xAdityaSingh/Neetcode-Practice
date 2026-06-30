class Solution {
public:
    void func(string s,int lb,int rb, vector<string> &ans){
        if(rb==0 and lb==0){
            ans.push_back(s);
            return;
        }
        if(lb>0) func(s+"(", lb-1,rb+1,ans);      
        if(rb>0) func(s+")", lb,rb-1,ans);
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func("",n,0,ans);
        return ans;
        
    }
};