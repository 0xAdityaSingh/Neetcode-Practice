class Solution {
public:
    long long func(vector<int>&v, int mid){
         long long ans = 0;
        for(auto it:v){
            ans+= ceil((double)(it)/(double)(mid));
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1, high = *max_element(v.begin(),v.end());
        while(low<=high){
            int mid = (low+high) / 2;
            long long totalHours = func(v,mid);
            if(totalHours<=h){
                high = mid -1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};