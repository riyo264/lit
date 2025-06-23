/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return ValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool ValidBST(TreeNode* root, long min, long max) {
        if(root == NULL) {
            return true;
        }
        if(root->val <= min || root->val >= max) {
            return false;
        }
        return ValidBST(root->left, min, root->val) && ValidBST(root->right, root->val, max);
    }
};