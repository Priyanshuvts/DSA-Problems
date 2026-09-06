class Solution {
public:
    int solve(string &s,string &t,vector<vector<long long>> &dp, int i = 0, int j = 0) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = solve(s, t, dp, i + 1 , j);
        if(s[i] == t[j]) {
            ans += solve(s, t, dp,i + 1, j + 1);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(s,t,dp);
    }
};