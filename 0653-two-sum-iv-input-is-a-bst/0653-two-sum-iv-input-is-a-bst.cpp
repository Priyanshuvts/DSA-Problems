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
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> next , prev;
        TreeNode* ptr = root;
        while(ptr){
            next.push(ptr);
            ptr = ptr -> left;
        }
        ptr = root;
        while(ptr){
            prev.push(ptr);
            ptr = ptr -> right;
        }
        while(!next.empty() && !prev.empty() && next.top()->val < prev.top()->val){
            if(next.top() -> val + prev.top() -> val == k) return true;
            else if(next.top() -> val + prev.top() -> val < k){
                ptr = next.top();
                next.pop();
                if(ptr -> right){
                    next.push(ptr -> right);
                    ptr = ptr -> right;
                    while(ptr){
                        next.push(ptr);
                        ptr = ptr -> left;
                    }
                }
            }
            else {
                ptr = prev.top();
                prev.pop();
                if(ptr -> left){
                    prev.push(ptr -> left);
                    ptr = ptr -> left;
                    while(ptr){
                        prev.push(ptr);
                        ptr = ptr -> right;
                    }
                }
            }
        }
        return false;
    }
};