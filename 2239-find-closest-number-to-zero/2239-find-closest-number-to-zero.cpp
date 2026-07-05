class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            if(abs(ans) == abs(nums[i])) ans = max(ans , nums[i]);
            if(abs(ans) > abs(nums[i])){
                ans = nums[i];
            }
        }
        return ans;
    }
};