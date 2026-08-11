class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix_sum = nums[0], n = nums.size();
        for(int j= 1 ; j < n; j++){
            if(nums[j] == nums[j - 1] + 1){
                prefix_sum += nums[j];
            }
            else break;
        }
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n; i ++){
            if(nums[i] == prefix_sum) prefix_sum ++;
        }
        return prefix_sum;
    }
};