class Solution {
public:
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& path, vector<vector<int>>& results) {
        if (remaining == 0) {
            results.push_back(path);
            return;
        }
        if (remaining < 0) return;

        for (int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i, path, results);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> path;
        backtrack(candidates, target, 0, path, results);
        return results;
    }
};