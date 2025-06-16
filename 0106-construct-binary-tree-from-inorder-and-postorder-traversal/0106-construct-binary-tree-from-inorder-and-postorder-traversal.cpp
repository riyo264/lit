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
    TreeNode* BuildTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if(postStart > postEnd || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsleft = inRoot - inStart;

        root->left = BuildTree(postorder, postStart, postStart+numsleft-1, inorder, inStart, inRoot-1, inMap);
        root->right = BuildTree(postorder, postStart+numsleft, postEnd-1, inorder, inRoot+1, inEnd, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i<inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        return BuildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
};