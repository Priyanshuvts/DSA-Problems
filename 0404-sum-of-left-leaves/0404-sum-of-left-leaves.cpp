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
    void helper(TreeNode* root , int& ans , int flag){
        if(root == NULL ) return;
        if(root -> left == NULL && root -> right == NULL ){
            if(flag) ans += root -> val;
            return;
        }
        helper(root -> left , ans , 1);
        helper(root -> right , ans , 0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root , ans , 0);
        return ans;
    }
};