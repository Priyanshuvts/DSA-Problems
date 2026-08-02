class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        for(int i = 0; i < n; ++i){
            sm += nums[i];
        }
        int ls = 0 , rs = sm;
        for(int i = 0; i < n; ++i){
            if(ls == (rs - nums[i])) return i;
            ls += nums[i];
            rs -= nums[i]; 
        }
        return -1;
    }
};