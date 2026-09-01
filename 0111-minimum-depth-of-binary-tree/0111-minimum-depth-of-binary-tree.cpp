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
    int mind(TreeNode* root , int& ans , int ct = 0){
        if(root == NULL) return ct;
        int left = mind(root -> left ,ans, ct + 1);
        int right = mind(root -> right ,ans, ct + 1);
        if(root -> left == NULL && root -> right == NULL) ans = min(ct + 1 , ans);
        return max(left , right);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = INT_MAX;
        mind(root , ans);
        return ans;
    }
};