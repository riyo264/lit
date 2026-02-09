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
    void Inorder(TreeNode* root, vector<int>& nodes) {
        if(root == NULL) {
            return;
        }
        Inorder(root->left, nodes);
        nodes.push_back(root->val);
        Inorder(root->right, nodes);
    }
    TreeNode* ConstructBST(vector<int>& nodes, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = ConstructBST(nodes, start, mid-1);
        node->right = ConstructBST(nodes, mid+1, end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        Inorder(root, nodes);
        int n = nodes.size();
        return ConstructBST(nodes, 0, n-1);
    }
};