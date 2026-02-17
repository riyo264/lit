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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        vector<vector<int>> ans;
        vector<int> lvl;
        int temp = 0;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            TreeNode* node = x.first;
            int l = x.second;
            if(temp != l) {
                if(!lvl.empty()) {
                    ans.push_back(lvl);
                }
                lvl = {};
                if(node != NULL) {
                    lvl.push_back(node->val);
                }
                temp = l;
            }
            else {
                if(node != NULL) {
                    lvl.push_back(node->val);
                }
            }
            if(node->left != nullptr) {
                q.push({node->left, l+1});
            }
            if(node->right != nullptr) {
                q.push({node->right, l+1});
            }
        }
        if(!lvl.empty()) {
            ans.push_back(lvl);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};