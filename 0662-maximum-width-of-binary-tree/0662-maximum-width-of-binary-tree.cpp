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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        if(root == NULL) {
            return 0;
        }
        queue <pair<TreeNode*, long long>> ds;
        ds.push({root, 0});
        while(!ds.empty()){
            int size = ds.size();
            long long min = ds.front().second;
            int first, last;
            for(int i = 0; i < size; i++)
            {
                long long cur_id = ds.front().second-min;
                TreeNode* node = ds.front().first;
                ds.pop();
                if(i == 0) first = cur_id;
                if(i == size-1) last = cur_id;
                if(node->left) {
                    ds.push({node->left, 2*cur_id+1});
                }
                if(node->right) {
                    ds.push({node->right, 2*cur_id+2});
                }
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};