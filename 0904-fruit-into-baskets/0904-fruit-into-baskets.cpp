class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0 , r = 0, ans = 0 ;
        unordered_map<int, int> mp;
        while(r < n){
            mp[fruits[r]] ++;
            while(mp.size() > 2) {
                if(mp[fruits[l]] == 1){
                    mp.erase(fruits[l]);
                    l ++;
                    break;
                }
                else {
                   mp[fruits[l]] --;
                   l  ++;
                }
            }
            r ++;
            ans = max(ans , r - l);
        }
        return ans;
    }
};