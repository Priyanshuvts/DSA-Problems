/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root , int& ans , int sm =0){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            sm = sm * 10 + root -> val;
            ans += sm;
            return;
        }
        helper(root -> left , ans , sm * 10 + root -> val);
        helper(root -> right , ans ,  sm * 10 + root -> val);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root , ans);
        return ans;
    }
};