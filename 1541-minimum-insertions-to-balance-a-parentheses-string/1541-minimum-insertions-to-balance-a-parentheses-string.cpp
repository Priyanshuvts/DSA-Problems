class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        for(int i = 0; i < n; ){
            if(s[i] == '(') st.push(s[i]);
            else {
                if(!st.empty()){
                    if(i + 1 < n && s[i + 1] == ')') {
                        st.pop();
                        i ++;
                    }
                    else {
                        ans ++;
                        st.pop();
                    }
                }
                else {
                    if(i + 1 < n && s[i + 1] == ')'){
                        ans ++;
                        i ++;
                    }
                    else{
                        ans += 2;
                    }
                }
            }
            i ++;
        }
        while(!st.empty()){
            ans += 2;
            st.pop();
        }
        return ans;
    }
};