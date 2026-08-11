class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = 0 , ct = 0;
        while(r < n - 1){
            int farthest = 0;
            while(l <= r){
                farthest = max(farthest , l + nums[l]);
                l++;
            }
            l = r + 1;
            r = farthest;
            ct ++;
        }
        return ct;
    }
};