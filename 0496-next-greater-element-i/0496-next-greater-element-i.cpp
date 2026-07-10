class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i ++){
            for(int j = 0; j < nums2.size(); ++j){
                if(nums1[i] == nums2[j]) ans[i] = j;
            }
        }
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            if(st.empty()){
                st.push(nums2[i]);
                nums2[i] = -1;
            }
            else if(st.top() > nums2[i]){
                int temp = nums2[i];
                nums2[i] = st.top();
                st.push(temp);
            }
            else{
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()) {
                    st.push(nums2[i]);
                    nums2[i] = -1 ;
                }
                else {
                    int tmp = nums2[i];
                    nums2[i] = st.top();
                    st.push(tmp);
                }
            }
        }
        for(int i = 0; i < ans.size(); i++){
            ans[i] = nums2[ans[i]];
        }
        return ans;
    }
};