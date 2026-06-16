class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int s(0),e(heights.size()-1);

        while(s<e){
            int tempHeight = min(heights[s],heights[e]);
            ans = max(ans, (tempHeight*(e-s)));
            if(heights[s]<heights[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};
