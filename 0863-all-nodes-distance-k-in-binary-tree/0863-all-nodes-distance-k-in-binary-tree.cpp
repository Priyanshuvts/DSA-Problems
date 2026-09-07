/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void help(TreeNode* target , int k , vector<int> & ans , unordered_map<TreeNode* , TreeNode*>& parent , unordered_map<TreeNode* , int>& visited){
    if(target == NULL) return;
    if(k == 0){
        ans.push_back(target -> val);
        return;
    }
    visited[target] = 1;
    if(parent.find(target) != parent.end() && visited.find(parent[target]) == visited.end()){
        help(parent[target] , k - 1 , ans , parent , visited);
    }
    if(visited.find(target -> left) == visited .end()){
        help(target -> left , k - 1 , ans , parent , visited);
    }
    if(visited.find(target -> right) == visited.end()){
        help(target -> right , k - 1 , ans , parent , visited);
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode* , TreeNode*> parent;
        q.push(root);
        TreeNode* tmp = root;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp -> left != NULL){
                q.push(tmp -> left);
                parent[tmp -> left] = tmp;
            }
            if(tmp -> right != NULL){
                q.push(tmp -> right);
                parent[tmp -> right] = tmp;
            }
        }
        vector<int> ans;
        unordered_map<TreeNode* , int> visited;
        help(target , k , ans , parent , visited);
        return ans;
    }
};