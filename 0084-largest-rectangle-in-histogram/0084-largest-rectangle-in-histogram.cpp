class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> lsi(n) , rsi (n);
        stack<int> l ,r;
        for(int i = 0; i < n ; i ++){
            while(!l.empty() && h[l.top()] >= h[i]){
                l.pop();
            }
            if(l.empty()) lsi[i] = -1;
            else lsi[i] = l.top();
            l.push(i);
        }
        for(int i = n - 1; i >= 0; i --){
            while(!r.empty() && h[r.top()] >= h[i]) r.pop();
            if(r.empty()) rsi[i] = n;
            else rsi[i] = r.top();
            r.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i ++){
            int rec = (rsi[i] - lsi[i] - 1) * h[i];
            ans = max(rec , ans);
        }

        return ans;
    }
};