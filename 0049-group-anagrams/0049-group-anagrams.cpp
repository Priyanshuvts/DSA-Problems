class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int  n = strs.size();
        unordered_map<string,int> mp;
        for(int i = 0; i < n; i ++){
            string str = strs[i];
            sort(str.begin() , str.end());
            if(mp.find(str) == mp.end()){
                ans.push_back({});
                ans.back().push_back(strs[i]);
                mp[str] = ans.size() - 1;
            }
            else{
                ans[mp[str]].push_back(strs[i]);
            }
        }
        return ans;
    }
};