class Solution {
private:
    void brackets(vector<string>& brs, int n, int bo = 0, int bc = 0, string s = "") {
        if (bo > n || bc > bo) return;

        if (bo == n && bc == n) {
            brs.push_back(s);
            return;
        }

        brackets(brs, n, bo + 1, bc, s + '(');

        brackets(brs, n, bo, bc + 1, s + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        brackets(ans , n);
        return ans;
    }
};