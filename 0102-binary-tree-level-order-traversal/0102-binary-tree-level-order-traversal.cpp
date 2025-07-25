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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==0)
        {
            int size = q.size();
            vector<int> levels;
            for(int i = 0; i<size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                levels.push_back(node->val);
            }
            ans.push_back(levels);
        }
        return ans;
    }
};