class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin() , s.end());
        string s1 = s[0];
        string s2 = s[s.size() - 1];
        string ans = "";
        for(int i = 0; i < min(s1.size() , s2.size()) ; i ++){
            if(s1[i] != s2[i]) break;
            ans += s1[i];
        }
        return ans;
    }
};