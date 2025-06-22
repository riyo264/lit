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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == key) {
            return assist(root);
        }
        TreeNode* temp = root;
        while(root != NULL) 
        {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    root->left = assist(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = assist(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return temp;
    }

    TreeNode* assist(TreeNode* root) {
        if(root->left == NULL) {
            return root->right;
        }
        else if(root->right == NULL) {
            return root->left;
        }
        TreeNode* nodeRight = root->right;
        TreeNode* lastnode = lastrightNode(root->left);
        lastnode->right = nodeRight;
        return root->left;
    }

    TreeNode* lastrightNode(TreeNode* root) {
        if(root->right == NULL) {
            return root;
        }
        return lastrightNode(root->right);
    }
};