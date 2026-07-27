class Solution {
public:
    int trap(vector<int>& h) {
        int ans  = 0;
        int n = h.size();
        vector<int> lmax(n) , rmax(n);
        int l = h[0];
        int r = h[n - 1];
        for(int i = 0 ; i < n; i ++){        
            lmax[i] = l;
            l = max(h[i] , l);
        }
        for(int i = n - 1; i >= 0; i --){             
           rmax[i] = r;
           r = max(h[i] , r);
        }

        for(int i = 0; i < n ; i ++){
            if(h[i] < lmax[i] && h[i] < rmax[i]) ans = ans + min(lmax[i] , rmax[i]) - h[i];
        }
        
        return ans;
    }
};