class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0 , ct = 0 , ans = 0, zidx = -1;
        while(r < n){
            if(nums[r] == 0){
                ct ++;
            }
            if(ct > k){
                if(nums[l] == 0) ct --;
                l ++;
            }
            r ++;
            ans = max(ans , r - l);
        }
        return ans;
    }
};