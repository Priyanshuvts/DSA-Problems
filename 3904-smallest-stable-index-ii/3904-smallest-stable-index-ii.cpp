class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minr(n);
        int mnr = INT_MAX;
        for(int i = n - 1; i >= 0; i --){
            mnr = min(mnr , nums[i]);
            minr[i] = mnr;
        }
        int maxl = INT_MIN;
        for(int i = 0; i < n; i ++){
            maxl = max(maxl , nums[i]);
            if(maxl - minr[i] <= k) return i;
        }
        return -1;
    }
};