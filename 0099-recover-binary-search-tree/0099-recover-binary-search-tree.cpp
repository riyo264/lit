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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)) {
            if(middle) {
                last = root;
            }
            else {
                first = prev;
                middle = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = NULL;
        middle = NULL;
        last = NULL;
        inorder(root);
        if(first && last) {
            swap(first->val, last->val);
        }
        else if(first && middle) {
            swap(first->val, middle->val);
        }
    }
};