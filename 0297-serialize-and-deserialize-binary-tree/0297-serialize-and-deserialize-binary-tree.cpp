class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                ans += "#,";
                continue;
            }
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> v;
        stringstream ss(data);
        string x;
        while (getline(ss, x, ',')) {
            v.push_back(x);
        }
        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < v.size()) {
            TreeNode* node = q.front();
            q.pop();
            if(v[i] != "#") {
                node->left = new TreeNode(stoi(v[i]));
                q.push(node->left);
            }
            i++;
            if(i < v.size() && v[i] != "#") {
                node->right = new TreeNode(stoi(v[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};