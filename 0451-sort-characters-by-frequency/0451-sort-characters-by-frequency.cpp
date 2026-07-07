class Solution {
private:
    char max_fq(map<char , int> mp){
        int mx = INT_MIN;
        char ans;
        for(auto it : mp){
            if(it.second > mx){
                mx = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
public:
    string frequencySort(string s) {
        map<char , int> mp;
        for(int i = 0; i < s.size(); i ++){
            mp[s[i]] ++;
        }
        int j = 0;
        while(true){
            char ch = max_fq(mp);
            if(mp[ch] == 0) break;
            for(int i = 0; i < mp[ch]; i ++){
                s[j] = ch;
                j ++;
            }
            mp[ch] = 0;
        }
        return s;
    }
};