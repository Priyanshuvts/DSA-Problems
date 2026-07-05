class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digit_sum = 0;
        int el_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            int n = nums[i];
            el_sum += n;
            while(n){
                digit_sum += n % 10;
                n /= 10;
            }
        }
        return el_sum - digit_sum;
    }
};