class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int bo = 0 , bc = 0;
        for(int i = 0; i < s.size(); ++i){
            if(bo == 0){
                bo ++;
                continue;
            }
            if(s[i] == '(') {
                bo ++;
                ans += "(";
            }
            else {
                bc ++;
                if(bo == bc){
                    bo = 0;
                    bc = 0;
                    continue;
                }
                ans += ")";
            }
        }
        return ans;
    }
};