class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') check.push(c);
            else{
                if( check.empty() || (c == ')' and check.top()!='(') || (c == '}' and check.top()!='{') || (c == ']' and check.top()!='[')) {return false;}
            check.pop();
            }
        }
        return check.empty();
    }
};