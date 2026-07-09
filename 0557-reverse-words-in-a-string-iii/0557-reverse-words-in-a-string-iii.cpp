class Solution {
private:
    string rev(string s){
        int n = s.size();
        for(int i = 0; i < n / 2; ++i){
            swap(s[i] , s[n - i -1]);
        }
        return s;
    }
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == ' '){
                ans += rev(word);
                ans += " ";
                word = "";
            }
            else word += s[i];
        }
        if(!word.empty()) ans += rev(word);
        return ans;
    }
};