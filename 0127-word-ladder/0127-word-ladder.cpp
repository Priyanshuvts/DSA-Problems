class Solution {
    bool diff1(string s1 , string s2){
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        int ct = 0;
        for(int i = 0; i < n ; i ++){
            if(s1[i] != s2[i]) ct ++;
        }
        if(ct == 1) return true;
        return false;
    }
public:
    int ladderLength(string src, string des, vector<string>& wl) {
        if(src == des) return 1;
        queue<string> q;
        q.push(src);
        int ct = 1;
        unordered_map<string , int> vis;
        vis[src] = 1;
        while(!q.empty()){
            int  n = q.size();
            while(n --){
                string s1 = q.front();
                q.pop();
                for(int i = 0; i < wl.size(); i ++){
                    if(diff1(s1 , wl[i]) && vis.find(wl[i]) == vis.end()){
                        vis[wl[i]] = 1;
                        q.push(wl[i]);
                        if(wl[i] == des) return ct + 1;
                    }
                }
            }
            ct ++;
        }
        return 0;
    }
};