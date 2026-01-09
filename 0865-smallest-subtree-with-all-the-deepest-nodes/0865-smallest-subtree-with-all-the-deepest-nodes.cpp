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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> rel;
        rel[root] = NULL;
        vector<TreeNode*> lastlevel;
        while(!q.empty()) 
        {
            int len = q.size();
            lastlevel.clear();
            for(int i = 0; i < len; i++) 
            {
                TreeNode* node = q.front();
                q.pop();
                lastlevel.push_back(node);
                if(node->left) {
                    rel[node->left] = node;
                    q.push(node->left);
                }
                if(node->right) {
                    rel[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        unordered_set<TreeNode*> parents(lastlevel.begin(), lastlevel.end());
        while(parents.size() > 1) {
            unordered_set<TreeNode*> next;
            for(auto x : parents) {
                next.insert(rel[x]);
            }
            parents = next;
        }
        return *parents.begin();
    }
};