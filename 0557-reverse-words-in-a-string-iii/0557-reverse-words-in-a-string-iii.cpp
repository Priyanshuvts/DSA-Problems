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
        stringstream ss(s);
        string word;
        string ans;
        while(ss >> word){
            ans += rev(word);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};