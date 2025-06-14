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
    int countNodes(TreeNode* root) {
        int total = 0;
        if(root == NULL ) {
            return total;
        }
        if(root->val || root->val==0) {
            total++;
        }
        countNodes2(root->left, total);
        countNodes2(root->right, total);
        return total;
    }

    void countNodes2(TreeNode* root, int& total) {
        if(root == NULL) {
            return;
        }
        if(root->val || root->val==0) {
            total++;
        }
        countNodes2(root->left, total);
        countNodes2(root->right, total);
    }
};