
class Solution {
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    void dfs(string word, string& begin, vector<string>& path) {
        if(word == begin) {
            vector<string> temp(path.rbegin(), path.rend());
            ans.push_back(temp);
            return;
        }
        for(auto& p : parent[word]) {
            path.push_back(p);
            dfs(p, begin, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return {};
        queue<string> q;
        unordered_map<string, int> dist;
        q.push(beginWord);
        dist[beginWord] = 0;
        int shortest = INT_MAX;
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int d = dist[word];
            if(d >= shortest) break;
            for(int i = 0; i < word.size(); i++) {
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == word[i]) continue;
                    temp[i] = c;
                    if(!st.count(temp)) continue;
                    if(!dist.count(temp)) {
                        dist[temp] = d + 1;
                        parent[temp].push_back(word);
                        q.push(temp);
                    }
                    else if(dist[temp] == d + 1) {
                        parent[temp].push_back(word);
                    }
                    if(temp == endWord)shortest = d + 1;
                }
            }
        }
        if(!dist.count(endWord)) return {};
        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);
        return ans;
    }
};
