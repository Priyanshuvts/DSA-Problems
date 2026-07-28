class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n) , nse(n) , nge(n) , pge(n);
        stack<int> ps , ns, ng , pg;
        for(int i = n- 1; i >= 0; i --){
            while(!ns.empty() && arr[ns.top()] >= arr[i]) ns.pop();
            if(ns.empty()) nse[i] = n ;
            else nse[i] = ns.top();
            ns.push(i);
        }
        for(int i = 0; i < n; i ++){
            while(!ps.empty() && arr[ps.top()] > arr[i]) ps.pop();
            if(ps.empty()) pse[i] = -1;
            else pse[i] = ps.top();
            ps.push(i);
        }
        for(int i = 0; i < n; i ++){
            while(!pg.empty() && arr[pg.top()] < arr[i]) pg.pop();
            if(pg.empty()) pge[i] = -1;
            else pge[i] = pg.top();
            pg.push(i);
        }
        for(int i = n- 1; i >= 0; i --){
            while(!ng.empty() && arr[ng.top()] <= arr[i]) ng.pop();
            if(ng.empty()) nge[i] = n ;
            else nge[i] = ng.top();
            ng.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n ; i ++){
            int ls = i - pse[i] , rs = nse[i] - i;
            int lg = i - pge[i] , rg = nge[i] - i;
            ans = ans + (1LL * arr[i] * lg * rg) - (1LL * arr[i] * ls * rs);
        }
        return ans;
    }
};