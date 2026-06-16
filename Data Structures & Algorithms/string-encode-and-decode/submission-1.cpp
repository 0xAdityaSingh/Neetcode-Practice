class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i = 0; i<strs.size();i++){
            if(strs[i]==""){
                strs[i] = " ";
            }
            if(i+1 == strs.size()){
                ans+=strs[i];
            }
            else{
                ans+=strs[i]+";";
            }
        }
        return ans;
    }

    vector<string> decode(string str) {
        string s;
        stringstream ss(str);
        vector<string> v;
        while (getline(ss, s, ';')) {
            v.push_back(s);
        }
        for(int i = 0; i<v.size();i++){
            if(v[i] == " "){
                v[i] = "";
            }
        }
        return v;
    }
};
