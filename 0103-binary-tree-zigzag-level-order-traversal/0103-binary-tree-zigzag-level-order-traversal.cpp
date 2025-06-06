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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> QueueNodes;
        QueueNodes.push(root);
        bool LtoR = true;

        while(!QueueNodes.empty()) {
            int size = QueueNodes.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++)
            {
                TreeNode* nodes = QueueNodes.front();
                QueueNodes.pop();
                int index;
                if(LtoR == true)
                {
                    index = i;
                }
                else {
                    index = size - 1 - i;
                }
                level[index] = nodes->val;
                if(nodes->left) {
                    QueueNodes.push(nodes->left);
                }
                if(nodes->right) {
                    QueueNodes.push(nodes->right);
                }
            }
                LtoR = !LtoR;
                ans.push_back(level);
            }
         return ans;   
        }
};