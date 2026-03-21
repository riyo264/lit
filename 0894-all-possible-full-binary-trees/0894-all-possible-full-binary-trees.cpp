class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (dp.count(n)) return dp[n];
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return dp[n] = res;
        }
        if (n % 2 == 0) return {};
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> leftTrees = allPossibleFBT(i);
            vector<TreeNode*> rightTrees = allPossibleFBT(n - 1 - i);
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return dp[n] = res;
    }
};