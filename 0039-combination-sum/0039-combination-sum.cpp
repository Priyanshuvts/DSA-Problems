class Solution {
private:
    void subs(vector<vector<int>>& ans , vector<int> cd , int k ,int idx = 0,vector<int> apd = {}){
        if(idx == cd.size()){
            if(k == 0) ans.push_back(apd);
            return;
        }
        if(cd[idx] <= k){
            apd.push_back(cd[idx]);
            subs(ans , cd , k - cd[idx] , idx , apd);
            apd.pop_back();
        }
        subs(ans,cd , k , idx + 1 , apd);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        subs(ans, candidates, target);
        return ans;
    }
};