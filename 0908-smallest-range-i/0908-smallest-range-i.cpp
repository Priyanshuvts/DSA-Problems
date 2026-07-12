class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            mn = min(nums[i] , mn);
            mx = max(nums[i] , mx);
        }
        int ans = mx - mn - 2 * k;
        if(ans < 0) return 0;
        return ans;
    }
};