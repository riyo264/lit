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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* leaf = cur->left;
            if(cur->left!=NULL) {
                q.push(leaf);
                if(leaf->left == NULL && leaf->right == NULL) {
                    sum = sum + (leaf->val);
                }
            }
            if(cur->right!=NULL) {
                q.push(cur->right);
            }
        }
        return sum;
    }
};