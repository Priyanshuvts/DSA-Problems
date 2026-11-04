class Solution {
private:
    bool dfs(vector<vector<int>>& g , int i , int j , int& m , int& n , int& ct){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return true;
        }
        if(g[i][j] == 0) {
            ct --;
            return false;
        }
        g[i][j] = 0;
        bool up = dfs(g , i - 1 , j , m , n , ++ct);
        bool dn = dfs(g , i + 1 , j , m , n , ++ct);
        bool left = dfs(g , i , j - 1 , m , n , ++ct);
        bool right = dfs(g , i , j + 1 , m , n , ++ct);
        return up || dn || left || right;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 1){
                    int ct = 1;
                    if(!dfs(grid , i , j , m , n , ct)) ans += ct;
                }
            }
        }
        return ans;
    }
};