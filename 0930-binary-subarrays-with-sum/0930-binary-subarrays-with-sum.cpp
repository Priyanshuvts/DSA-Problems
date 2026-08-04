class Solution {
int less_equal(vector<int>& nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int l = 0 , r = 0 , ans = 0 ,sm = 0;
    while(r < n){
        sm += nums[r];
        while(sm > goal){
            sm -= nums[l];
            l ++;
        }
        ans += r - l + 1;
        r ++;
    }
    return ans;
}
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return less_equal(nums , goal) - less_equal(nums , goal - 1);
    }
};