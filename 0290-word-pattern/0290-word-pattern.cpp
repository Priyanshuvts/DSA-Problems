class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m1;
        unordered_map<string, char> m2;
        stringstream ss(s);
        string word;
        int i = 0;
        while(ss >> word){
            if(i >= pattern.size()) return false;
            if(m1.find(pattern[i]) == m1.end()) m1[pattern[i]] = word;
            else if (m1[pattern[i]] != word) return false;
            if(m2.find(word) == m2.end()) m2[word] = pattern[i];
            else if(m2[word] != pattern[i]) return false; 
            i ++;
        }
        if(i < pattern.size()) return false;
        return true;
    }
};