class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int curr = 1 , right = 1;
        vector<int> left(n , 1);
        for(int i= 1; i < n; i ++){
            if(ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int ans = max(left[n - 1] , curr);
        for(int i = n - 2; i >= 0; i --){
            if(ratings[i] > ratings[i + 1]){
                curr = right + 1;
                right += 1;
            }
            else {
                curr = 1;
                right = 1;
            }
            ans += max(left[i] , curr);
        }
        return ans;
    }
};