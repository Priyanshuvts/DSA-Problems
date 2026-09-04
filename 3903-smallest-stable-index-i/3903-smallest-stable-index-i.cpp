class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> help(n);
        int minr = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            minr = min(nums[i] , minr);
            help[i] = minr;
        }
        int maxl = INT_MIN;
        for(int i = 0; i < n; i ++){
            maxl = max(nums[i] , maxl);
            if(maxl - help[i] <= k) return i;
        }
        return - 1;
    }
};