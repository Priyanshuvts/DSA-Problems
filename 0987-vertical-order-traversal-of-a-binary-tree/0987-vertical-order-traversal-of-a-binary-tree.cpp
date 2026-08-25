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
    void helper(TreeNode* root,int row,int col,map<int,vector<pair<int,int>>>&mp){
        if(!root) return;
        mp[col].push_back({row,root->val});
        helper(root->left,row+1,col-1,mp);
        helper(root->right,row+1,col+1,mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int,vector<pair<int,int>>> mp;
        helper(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto &x:mp){
            sort(x.second.begin(), x.second.end());
            vector<int> v;
            for(auto &p:x.second) v.push_back(p.second);
            ans.push_back(v);
        }
        return ans;
    }
};