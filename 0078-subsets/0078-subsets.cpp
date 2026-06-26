class Solution {
private:
    void subs(vector<int> v ,vector<vector<int>>& ret, int i = 0 , vector<int> ans = {}){
        if(i == v.size()){
            ret.push_back(ans);
            return;
        }
        ans.push_back(v[i]);
        subs(v ,ret , i + 1, ans);
        ans.pop_back();
        subs(v ,ret , i + 1 , ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        subs(nums , ans);
        return ans;
    }
};