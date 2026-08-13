class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0 ;
        vector<int> store1(n , 1);
        vector<int> store2(n , 1);
        for(int i= 1; i < n; i ++){
            if(ratings[i] > ratings[i - 1]) {
                store1[i] = store1[i - 1] + 1;
            }
        }
        for(int i = n - 2; i >= 0; i --){
            if(ratings[i] > ratings[i + 1]){
                store2[i] = store2[i + 1] + 1;
            }
        }
        for(int i = 0; i < n; i ++){
            ans += max(store1[i] , store2[i]);
        }
        return ans;
    }
};