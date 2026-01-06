class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int bestLevel = 1;
        long long maxSum = LLONG_MIN;
        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            level++;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                bestLevel = level;
            }
        }
        return bestLevel;
    }
};
