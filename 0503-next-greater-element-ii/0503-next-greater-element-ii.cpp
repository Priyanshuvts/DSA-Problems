class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        bool flag = true;
        for(int i = n - 1; i >= 0; i --){
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(st.empty()){
                nge[i] = -1;
            }
            else{
                nge[i] = st.top();
            }
            st.push(nums[i]);
            if(i == 0 && flag == true){
                i = n;
                flag = false;
            }
        }
        return nge;
    }
};