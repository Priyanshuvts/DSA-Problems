class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mp = {{'(',')'},{'{','}'},{'[',']'}};
    for(int i = 0; i < s.size(); ++i){
        if(mp.find(s[i]) != mp.end()){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            if(mp[st.top()] != s[i]) return false;
            st.pop();
        }
    }
    if(!st.empty()) return false;
    return true;
}
};