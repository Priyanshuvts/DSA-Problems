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
    int check(TreeNode* root , int ht = 0){
        if(root == NULL) return ht;

        int left = check(root -> left, ht + 1);
        int right = check(root -> right , ht + 1);
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return max(left , right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int n = check(root);
        return n == -1 ? false : true ;
    }
};