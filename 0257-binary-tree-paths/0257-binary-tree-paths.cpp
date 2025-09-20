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
    void dfs(TreeNode* root, vector<string>& res, string s) {
        if(root == NULL) {
            return;
        }
        if(!s.empty()) {
            s += "->";
        }
        int n = root->val;
        s = s + to_string(n);
        if(root->left == NULL && root->right == NULL) {
            res.push_back(s);
            return;
        }
        dfs(root->left, res, s);
        dfs(root->right, res, s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        if(root == NULL) {
            return res;
        }
        dfs(root, res, s);
        return res;
    }
};