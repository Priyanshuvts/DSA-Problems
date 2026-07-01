class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        int x = 1 << n;
        vector<vector<int>> ans;
        for(int i = 0; i < x; i++){
            vector<int> push;
            int j = i;
            int ct = 0;
            while(j){
                if(j & 1) push.push_back(v[ct]);
                j = j >> 1;
                ct ++;
            }
            ans.push_back(push);
        }
        return ans;
    }
};