class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        if(n == k) return "0";
        int i = 0;
        string st = "";
        for(int i = 0 ;i < n; i ++){
            while(!st.empty() && st.back() > s[i] && k > 0){
                st.pop_back();
                k --;
            }
            if(st.empty() && s[i] == '0') continue;
            st.push_back(s[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop_back();
            k --;
        }
        if(st.empty()) return "0";
        return st;
    }
};