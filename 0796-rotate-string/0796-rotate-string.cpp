class Solution {
public:
    bool rotateString(string s, string k) {
       s += s;
       if(s.find(k) != string::npos) return true;
       return false;
    }
};