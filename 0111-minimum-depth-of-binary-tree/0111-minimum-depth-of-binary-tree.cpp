class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = q.front(); q.pop();

                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            depth++;
        }

        return 0;
    }
};
