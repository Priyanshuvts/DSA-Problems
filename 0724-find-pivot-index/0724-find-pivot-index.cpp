class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        for(int i = 0; i < n ; i++){
            sm += nums[i];
        }
        int left = sm;
        int right = 0;
        int idx = -1;
        for(int i = n - 1; i >= 0; i --){
            left -= nums[i];
            if(left == right) idx = i;
            right += nums[i];
        }
        return idx;
    }
};