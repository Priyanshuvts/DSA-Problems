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
    void helper(TreeNode* root , vector<string> & ans , string add = ""){
        if(root == NULL ) return;
        if(root -> left == NULL && root -> right == NULL){
            add += to_string(root -> val);
            ans.push_back(add);
            return;
        }
        add += to_string(root -> val);
        add += "->";
        helper(root -> left , ans ,add);
        helper(root -> right , ans ,add);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root , ans);
        return ans;
    }
};