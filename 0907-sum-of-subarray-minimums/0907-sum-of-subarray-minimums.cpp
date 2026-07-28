class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        vector<int> nse(n);
        stack<int> st;
        for(int i = n- 1; i >= 0; i --){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nse[i] = n ;
            else nse[i] = st.top();
            st.push(i);
        }
        vector<int> pse(n);
        stack<int> s;
        for(int i = 0; i < n; i ++){
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            if(s.empty()) pse[i] = -1;
            else pse[i] = s.top();
            s.push(i);
        }
        for(int i = 0; i < n ; i ++){
            int ctr = nse[i] - i ;
            int ctl = i - pse[i] ;
            ans = (ans + 1LL * arr[i] * ctr * ctl) % 1000000007;
        }
        return ans ;
    }
};
